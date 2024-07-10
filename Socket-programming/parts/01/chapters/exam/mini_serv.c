#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

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
    int         numberOfClient;
}   t_server;

void    checkArgumentCount(int count);
void    handleError(char *message);

int main(int argc, char *argv[]) {
    t_server    server;

    checkArgumentCount(argc);
    initializeServer(&server);
    return (0);
}

void    checkArgumentCount(int count) {
    if (count < 2)
        handleError("Wrong number of arguments");
}

void    initializeServer(t_server *server) {
    server->socket.server = socket(PF_INET, SOCK_STREAM, 0);
    if (server->socket.server == -1)
        handleError("Fatal error");
    server->socket.client = -1;
    server->socket.max = server->socket.server;
    memset(&server->address.server, 0, sizeof(server->address.server));
    memset(&server->address.client, 0, sizeof(server->address.client));
    server->address.size = sizeof(server->address.client);
}

void    handleError(char *message) {
    write(STDERR_FILENO, message, strlen(message));
    write(STDERR_FILENO, '\n', 1);
    exit(1);
}