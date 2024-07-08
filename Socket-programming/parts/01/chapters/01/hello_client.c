#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void    handleError(char *message);

int main(int argc, char *argv[]) 
{
    int                 clientSocket;
    struct sockaddr_in  serverAddress;
    char                message[30];
    int                 stringLength;

    if (argc != 3) 
    {
        printf("Usage: %s <IP> <port> \n", argv[0]);
        exit(1);
    }

    clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1)
        handleError("socket() error");

    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(argv[1]);
    serverAddress.sin_port = htons(atoi(argv[2]));

    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
        handleError("connect() error");

    stringLength = read(clientSocket, message, sizeof(message) - 1);
    if (stringLength == -1)
        handleError("read() error");

    printf("Message from server: %s \n", message);
    close(clientSocket);
    return (0);
}

void    handleError(char *message) 
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}