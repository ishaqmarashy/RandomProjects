#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
//debugbreak adds a breakpoint where x evals to false
#define ASSERT(x) if (!(x)) __debugbreak();
//runs clear error before calling the function x then calls log call
//with the values #x which is the name of the function converted to string
//file name and line number
#define GLCall(x) glClearErrors();\
	x;\
	ASSERT(glLogCall(#x,__FILE__,__LINE__))

unsigned int ParseShader(const std::string& filepath);
bool glLogCall(const char* function, const char* file, int line);
void glClearErrors();