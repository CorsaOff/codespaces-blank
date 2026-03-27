 #include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const int PORT = 8080;
const int BUFFER_SIZE = 1024;

int main()
{
    using namespace std;
    std::cout << "ping" << " 4";
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        std::cerr << "serverSocket < 0 \n";
        return 1; // скорее без ретерн
    }
    std::cout << "сокет создан";
    sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    //socklen_t serverAddrSize = sizeof(serverAddr)
    if ( bind ( serverSocket, (sockaddr*)&serverAddr, sizeof (serverAddr)) < 0)
    {
        std::cerr << "Ошибка bind";
        close(serverSocket);
        return 2;
    }
    std::cout << "сокет привязан \n";
    if (listen(serverSocket, 3) < 0)
    {
        std::cerr << "ошибка очереди";
        close(serverSocket);
        return 3;
    }

    std::cout << "Сервер слушает" << PORT;

    std::cout << "ожидаем клиента \n" ;
    sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (sockaddr *)&clientAddrSize, &clientAddrSize);
    if (clientSocket < 0)
    {
        close(serverSocket);
        return 4;
    }

    char clientIP[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &clientAddr.sin_addr, clientIP, INET_ADDRSTRLEN);
    std::cout << "Клиент подключен" << clientIP;

    char buffer[BUFFER_SIZE];
    while (true)
    {
        memset(buffer, 0, BUFFER_SIZE);
        int bytesRecieved = recv(clientSocket, buffer, BUFFER_SIZE - 1, 0);

        if ( bytesRecieved <= 0)
        {
            std::cout << "клиент отключился";
            break;
        }

        std::string message(buffer);
        if (message == "exit")
        {
            std::cout << "Выход";
            break;
        }
        std::string responce;
        if (message == "ping")
        {
            responce = "pong";
        }
        else
        {
            responce = "unknown command";
        }

        send(clientSocket, responce.c_str(), responce.length(), 0);
    }
        close (clientSocket);
        close (serverSocket);
        return 0;
}
