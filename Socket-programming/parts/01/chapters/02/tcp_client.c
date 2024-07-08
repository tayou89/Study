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
    struct sockaddr_in  serverAddress;
    char                message[30];
    int                 stringLength = 0;
    int                 index = 0, readSize = 0;

    if (argc != 3) 
    {
        printf("Usage: %s <IP> <port> \n", argv[0]);
        exit(1);
    }

    serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
        handleError("socket() error");

    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(argv[1]);
    serverAddress.sin_port = htons(atoi(argv[2]));

    if (connect(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
        handleError("connect() error");

    while ((readSize = read(serverSocket, &message[index++], 1)))
    {
        if (readSize == -1)
            handleError("read() error");
        stringLength += readSize;
    }

    printf("Message from server: %s \n", message);
    printf("Function read call count: %d\n", stringLength);
    close(serverSocket);
    return (0);
}

void    handleError(char *message) 
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}