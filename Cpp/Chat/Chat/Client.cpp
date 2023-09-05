#include <iostream>
#include <Winsock2.h>
#include <WS2tcpip.h>
#include <string>
#include <thread>
#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsData;
    if (WSAStartup(MAKEWORD(2, 2), &wsData) != 0) {
        std::cerr << "Failed to initialize Winsock." << std::endl;
        return 1;
    }

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create socket." << std::endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;

    // Convert the IP address from text to binary
    if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0) {
        std::cerr << "Invalid server address." << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    serverAddr.sin_port = htons(12345);

    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Failed to connect to the server." << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Connected to the server. You can start chatting." << std::endl;

    char buffer[1024];

    while (true) {
        std::string message;
        std::cout << "Enter your message: ";
        std::getline(std::cin, message);

        int bytesSent = send(clientSocket, message.c_str(), message.length(), 0);
        if (bytesSent == SOCKET_ERROR) {
            std::cerr << "Failed to send message." << std::endl;
            break;
        }

        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived <= 0) {
            std::cerr << "Server disconnected." << std::endl;
            break;
        }

        buffer[bytesReceived] = '\0';
        std::cout << "Received: " << buffer << std::endl;
    }

    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
