#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE    1024

void    handleError(char *message);

int main(int argc, char *argv[]) 
{
    int                 clientSocket;
    int                 readSize;
    int                 writeSize;
    int                 receiveSize;
    char                message[BUF_SIZE];
    struct sockaddr_in  serverAddress;
    
    if (argc != 3)
        handleError("<IP> <port> are needed");
    clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1)
        handleError("socket() error");
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = PF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(argv[1]);
    serverAddress.sin_port = htons(atoi(argv[2]));
    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
        handleError("connect() error");
    else
        puts("Connected.............");

    while (1) 
    {
        fputs("Input message(Q to quit): ", stdout);
        fgets(message, BUF_SIZE, stdin);
        if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
            break ;
        writeSize = write(clientSocket, message, strlen(message));
        receiveSize = 0;
        while (receiveSize < writeSize)
        {
            readSize = read(clientSocket, message, BUF_SIZE - 1);
            if (readSize == -1)
                handleError("read() error");
            receiveSize += readSize;
        }
        message[receiveSize] = '\0';
        printf("Message from server: %s", message);
    }
    close(clientSocket);
    return (0);
}

void    handleError(char *message) 
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}