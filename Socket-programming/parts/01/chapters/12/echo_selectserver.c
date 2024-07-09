#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE    100

void    handleError(char *message);

int main(int argc, char *argv[]) {
    int                 serverSocket;
    int                 clientSocket;
    int                 fdMax;
    int                 returnFd;
    int                 i;
    int                 readSize;
    char                buffer[BUF_SIZE];
    socklen_t           addressSize;
    struct sockaddr_in  serverAddress;
    struct sockaddr_in  clientAddress;
    struct timeval      timeout;
    fd_set              reads;
    fd_set              copy;

    if (argc != 2)
        handleError("Error: can't find port");
    serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = PF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(atoi(argv[1]));
    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1)
        handleError("bind() error");
    if (listen(serverSocket, 5) == -1)
        handleError("listen() error");
    FD_ZERO(&reads);
    FD_SET(serverSocket, &reads);
    printf("serverSocket: %d\n", serverSocket);
    fdMax = serverSocket;
    while (1) {
        copy = reads;
        timeout.tv_sec = 5;
        timeout.tv_usec = 5000;
        if ((returnFd = select(fdMax + 1, &copy, 0, 0, &timeout)) == -1)
            break ;
        if (returnFd == 0)
            continue ;
        for (i = 0; i < fdMax + 1; i++) {
            if (FD_ISSET(i, &copy)) {
                if (i == serverSocket) {
                    addressSize = sizeof(clientAddress);
                    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &addressSize);
                    FD_SET(clientSocket, &reads);
                    if (fdMax < clientSocket)
                        fdMax = clientSocket;
                    printf("connected client: %d\n", clientSocket);
                }
                else {
                    readSize = read(i, buffer, BUF_SIZE);
                    if (readSize == 0) {
                        FD_CLR(i, &reads);
                        close(i);
                        printf("closed client: %d\n", 1);
                    }
                    else
                        write(i, buffer, readSize);
                }
            }
        }
    }
    close(serverSocket);
    return (0);
}

void    handleError(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}