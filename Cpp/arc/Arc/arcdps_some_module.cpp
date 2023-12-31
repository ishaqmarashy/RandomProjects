/*
* arcdps combat api example
*/

#include <stdint.h>
#include <stdio.h>
#include <Windows.h>
#include "imgui/imgui.h"

/* arcdps export table */
typedef struct arcdps_exports {
	uintptr_t size; /* size of exports table */
	uint32_t sig; /* pick a number between 0 and uint32_t max that isn't used by other modules */
	uint32_t imguivers; /* set this to IMGUI_VERSION_NUM. if you don't use imgui, 18000 (as of 2021-02-02) */
	const char* out_name; /* name string */
	const char* out_build; /* build string */
	void* wnd_nofilter; /* wndproc callback, fn(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam), return assigned to umsg */
	void* combat; /* combat event callback, fn(cbtevent* ev, ag* src, ag* dst, char* skillname, uint64_t id, uint64_t revision) */
	void* imgui; /* ::present callback, before imgui::render, fn(uint32_t not_charsel_or_loading, uint32_t hide_if_combat_or_ooc) */
	void* options_end; /* ::present callback, appending to the end of options window in arcdps, fn() */
	void* combat_local;  /* combat event callback like area but from chat log, fn(cbtevent* ev, ag* src, ag* dst, char* skillname, uint64_t id, uint64_t revision) */
	void* wnd_filter; /* wndproc callback like wnd_nofilter above, input filered using modifiers */
	void* options_windows; /* called once per 'window' option checkbox, with null at the end, non-zero return disables arcdps drawing that checkbox, fn(char* windowname) */
} arcdps_exports;

/* combat event - see evtc docs for details, revision param in combat cb is equivalent of revision byte header */
typedef struct cbtevent {
	uint64_t time;
	uint64_t src_agent;
	uint64_t dst_agent;
	int32_t value;
	int32_t buff_dmg;
	uint32_t overstack_value;
	uint32_t skillid;
	uint16_t src_instid;
	uint16_t dst_instid;
	uint16_t src_master_instid;
	uint16_t dst_master_instid;
	uint8_t iff;
	uint8_t buff;
	uint8_t result;
	uint8_t is_activation;
	uint8_t is_buffremove;
	uint8_t is_ninety;
	uint8_t is_fifty;
	uint8_t is_moving;
	uint8_t is_statechange;
	uint8_t is_flanking;
	uint8_t is_shields;
	uint8_t is_offcycle;
	uint8_t pad61;
	uint8_t pad62;
	uint8_t pad63;
	uint8_t pad64;
} cbtevent;

/* agent short */
typedef struct ag {
	char* name; /* agent name. may be null. valid only at time of event. utf8 */
	uintptr_t id; /* agent unique identifier */
	uint32_t prof; /* profession at time of event. refer to evtc notes for identification */
	uint32_t elite; /* elite spec at time of event. refer to evtc notes for identification */
	uint32_t self; /* 1 if self, 0 if not */
	uint16_t team; /* sep21+ */
} ag;

/* proto/globals */
uint32_t cbtcount = 0;
arcdps_exports arc_exports;
char* arcvers;
void dll_init(HANDLE hModule);
void dll_exit();
extern "C" __declspec(dllexport) void* get_init_addr(char* arcversion, ImGuiContext * imguictx, void* id3dptr, HANDLE arcdll, void* mallocfn, void* freefn, uint32_t d3dversion);
extern "C" __declspec(dllexport) void* get_release_addr();
arcdps_exports* mod_init();
uintptr_t mod_release();
uintptr_t mod_wnd(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
uintptr_t mod_combat(cbtevent* ev, ag* src, ag* dst, char* skillname, uint64_t id, uint64_t revision);
void log_file(char* str);
void log_arc(char* str);
void mod_imgui(uint32_t not_charsel_or_loading, uint32_t hide_if_combat_or_ooc) ;
/* arcdps exports */
void* filelog;
void* arclog;

/* dll main -- winapi */
BOOL APIENTRY DllMain(HANDLE hModule, DWORD ulReasonForCall, LPVOID lpReserved) {
	switch (ulReasonForCall) {
	case DLL_PROCESS_ATTACH: dll_init(hModule); break;
	case DLL_PROCESS_DETACH: dll_exit(); break;

	case DLL_THREAD_ATTACH:  break;
	case DLL_THREAD_DETACH:  break;
	}
	return 1;
}

/* log to arcdps.log, thread/async safe */
void log_file(char* str) {
	size_t(*log)(char*) = (size_t(*)(char*))filelog;
	if (log) (*log)(str);
	return;
}

/* log to extensions tab in arcdps log window, thread/async safe */
void log_arc(char* str) {
	size_t(*log)(char*) = (size_t(*)(char*))arclog;
	if (log) (*log)(str);
	return;
}

/* dll attach -- from winapi */
void dll_init(HANDLE hModule) {
	return;
}

/* dll detach -- from winapi */
void dll_exit() {
	return;
}

/* export -- arcdps looks for this exported function and calls the address it returns on client load */
extern "C" __declspec(dllexport) void* get_init_addr(char* arcversion, ImGuiContext * imguictx, void* id3dptr, HANDLE arcdll, void* mallocfn, void* freefn, uint32_t d3dversion) {
	// id3dptr is IDirect3D9* if d3dversion==9, or IDXGISwapChain* if d3dversion==11
	arcvers = arcversion;
	filelog = (void*)GetProcAddress((HMODULE)arcdll, "e3");
	arclog = (void*)GetProcAddress((HMODULE)arcdll, "e8");
	ImGui::SetCurrentContext((ImGuiContext*)imguictx);
	ImGui::SetAllocatorFunctions((void* (*)(size_t, void*))mallocfn, (void (*)(void*, void*))freefn); // on imgui 1.80+
	return mod_init;
}

/* export -- arcdps looks for this exported function and calls the address it returns on client exit */
extern "C" __declspec(dllexport) void* get_release_addr() {
	arcvers = 0;
	return mod_release;
}

/* initialize mod -- return table that arcdps will use for callbacks. exports struct and strings are copied to arcdps memory only once at init */
arcdps_exports* mod_init() {
	/* for arcdps */
	memset(&arc_exports, 0, sizeof(arcdps_exports));
	arc_exports.sig = 0xFFFA;
	arc_exports.imguivers = IMGUI_VERSION_NUM;
	arc_exports.size = sizeof(arcdps_exports);
	arc_exports.out_name = "Some random shit";
	arc_exports.out_build = "0.1";
	arc_exports.wnd_nofilter = mod_wnd;
	arc_exports.combat = mod_combat;
	arc_exports.options_windows = 0;
	arc_exports.imgui = mod_imgui;
		//arc_exports.size = (uintptr_t)"error message if you decide to not load, sig must be 0";
	log_arc((char*)"combatdemo: done mod_init"); // if using vs2015+, project properties > c++ > conformance mode > permissive to avoid const to not const conversion error
	log_file((char*)"combatdemo: done mod init");
	return &arc_exports;
}

/* release mod -- return ignored */
uintptr_t mod_release() {
	FreeConsole();
	return 0;
}

/* window callback -- return is assigned to umsg (return zero to not be processed by arcdps or game) */
uintptr_t mod_wnd(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	/* much lazy */
	char buff[4096];
	char* p = &buff[0];

	/* yes */
	p += _snprintf_s(p, 400, _TRUNCATE, "byeeeeeeeeeeeeeee\n", (uintptr_t)hWnd);
	p += _snprintf_s(p, 400, _TRUNCATE, "byeeeeeeeeeeeeeee\n", uMsg, wParam, lParam);

	/* hotkey */
	if (uMsg == WM_KEYDOWN) {
		if (wParam == 0x43) {
			/* do something with c and don't pass to arc/game */
			return 0;
		}
	}

	return uMsg;
}

/* combat callback -- may be called asynchronously, use id param to keep track of order, first event id will be 2. return ignored */
/* at least one participant will be party/squad or minion of, or a buff applied by squad in the case of buff remove. not all statechanges present, see evtc statechange enum */
uintptr_t mod_combat(cbtevent* ev, ag* src, ag* dst, char* skillname, uint64_t id, uint64_t revision) {
	/* much lazy */
	char buff[4096];
	char* p = &buff[0];

	/* ev is null. dst will only be valid on tracking add. skillname will also be null */
	if (!ev) {

		/* notify tracking change */
		if (!src->elite) {
			p += _snprintf_s(p, 400, _TRUNCATE, "Tracking change for non-elite source\n");
		}

	/* combat event. skillname may be null. non-null skillname will remain static until client exit. refer to evtc notes for complete detail */
	else {
		/* common */
		p += _snprintf_s(p, 400, _TRUNCATE, "Combat event occurred\n");
		cbtcount += 1;
	}

	/* print */
	log_arc(&buff[0]);
	//log_file(&buff[0]);
	return 0;
}
	}
void mod_imgui(uint32_t not_charsel_or_loading, uint32_t hide_if_combat_or_ooc) {
    // Check if the character is not in the character selection screen or loading screen
            // Start a new ImGui frame
            ImGui::NewFrame();

            // Create a new window
            ImGui::Begin("My Custom Window");

            // Add some text to the window
            ImGui::Text("Hello, World!");

            // End the window
            ImGui::End();
}