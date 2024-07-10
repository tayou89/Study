#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/select.h>

typedef struct s_socket{
    int server;
    int client;
    int max;
}   t_socket;

typedef struct s_address {
    struct sockaddr_in  server;
    struct sockaddr_in  client;
    socklen_t           size;
}   t_address;

typedef struct s_client 
{
    int             socket;
    int             id;
    struct s_client *next;
}   t_client;

typedef struct s_server {
    t_socket    socket;
    t_address   address;
    t_client    *client;
    fd_set      fdSet;
    int         numberOfClient;
}   t_server;

void    checkArgumentCount(int count);
void    handleError(char *message);
void    initializeServer(t_server *server, int port);
void    initializeSocket(t_socket *sockets);
void    initializeAddress(t_address *address, int port);
void    initializeFdSet(fd_set *fdSet, int serverSocket);
void    makeServerSocketListen(int socket, struct sockaddr_in address);

int main(int argc, char *argv[]) {
    t_server    server;

    checkArgumentCount(argc);
    initializeServer(&server, atoi(argv[1]));
    makeServerSocketListen(server.socket.server, server.address.server);
    makeChattingLoop(&server);
    return (0);
}

void    checkArgumentCount(int count) {
    if (count < 2)
        handleError("Wrong number of arguments");
}

void    initializeServer(t_server *server, int port) {
    initializeSocket(&server->socket);
    initializeAddress(&server->address, port);
    initializeFdSet(&server->fdSet, server->socket.server);
}

void    initializeSocket(t_socket *sockets) {
    sockets->server = socket(PF_INET, SOCK_STREAM, 0);
    if(sockets->server == -1)
        handleError("Fatal error");
    sockets->client = -1;
    sockets->max = sockets->server;
}

void    initializeAddress(t_address *address, int port) {
    memset(&address->server, 0, sizeof(address->server));
    address->server.sin_family = PF_INET;
    address->server.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    address->server.sin_port = htons(port);
    memset(&address->client, 0, sizeof(address->client));
    address->size = sizeof(address->client);
}

void    initializeFdSet(fd_set *fdSet, int serverSocket) {
    FD_ZERO(&fdSet);
    FD_SET(serverSocket, &fdSet);
}

void    makeServerSocketListen(int socket, struct sockaddr_in address) {
    if (bind(socket, &address, sizeof(address)) == -1)
        handleError("Fatal error");
    if (listen(socket, 10) == -1)
        handleError("Fatal error");
}

void    makeChattingLoop(t_server *server) {
    int     numberOfSelectedFds;
    fd_set  readSet;
    fd_set  writeSet;

    while (1) {
        readSet = server->fdSet;
        writeSet = server->fdSet;
        numberOfSelectedFds = select(server->socket.max + 1, &readSet, &writeSet, 0, 0);
        if (numberOfSelectedFds <= 0) 
            continue ;
    }
} 

void    handleError(char *message) {
    write(STDERR_FILENO, message, strlen(message));
    write(STDERR_FILENO, '\n', 1);
    exit(1);
}