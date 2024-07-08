#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define BUF_SIZE    1024

void    handleError(char *message);

int main(int argc, char *argv[])
{
    int                 serverSocket;
    int                 clientSocket;
    int                 i, readSize;
    char                message[BUF_SIZE];
    struct sockaddr_in  serverAddress;
    struct sockaddr_in  clientAddress;
    socklen_t           clientAddressSize = sizeof(clientAddress);

    if (argc != 2) 
        handleError("Port is necessary");
    serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
        handleError("socket() error");
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = PF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(atoi(argv[1]));
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
        handleError("bind() error");
    if (listen(serverSocket, 5) == -1)
        handleError("listen() error");
    for (i = 0; i < 5; i++)
    {
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressSize);
        if (clientSocket == -1)
            handleError("accept() error");
        else
            printf("Connected client %d \n", i + 1);
        while ((readSize = read(clientSocket, message, BUF_SIZE)))
            write(clientSocket, message, readSize);
        close(clientSocket);
    }
    close(serverSocket);
    return (0);
}

void    handleError(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}