#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void    handleError(char *message);

int main(int argc, char *argv[])
{
    int                 serverSocket;
    int                 clientSocket;
    struct sockaddr_in  serverAddress;
    struct sockaddr_in  clientAddress;
    socklen_t           clientAddressSize;

    char message[] = "Hello World!";

    if (argc != 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
        handleError("socket() error");

    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(atoi(argv[1]));

    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1)
        handleError("bind() error");

    printf("before listen!\n");
    if (listen(serverSocket, 5) == -1)
        handleError(("listen() error"));
    printf("after listen!\n");
    
    clientAddressSize = sizeof(clientAddress);
    printf("before accepted!\n");
    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressSize);
    if (clientSocket == -1)
        handleError("accept() error");

    printf("after accepted!\n");
    write(clientSocket, message, sizeof(message));
    close(clientSocket);
    close(serverSocket);
    return (0);
}

void    handleError(char *message) 
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}