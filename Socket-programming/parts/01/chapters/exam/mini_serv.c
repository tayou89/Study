#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/select.h>

#define BUFFER_SIZE	1024

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

typedef struct s_client {
    int             socket;
    int             id;
    struct s_client *next;
    struct s_client *prev;
}   t_client;

typedef struct s_fdSet {
    fd_set  origin;
    fd_set  read;
    fd_set  write;
}   t_fdSet;

typedef struct s_server {
    t_socket    socket;
    t_address   address;
    t_fdSet     fdSet;
    t_client    *clientList;
    int         lastClientId;
}   t_server;

void    checkArgumentCount(int count);
void    handleError(char *message, t_server *server);
void    initializeServer(t_server *server, int port);
void    initializeSocket(t_socket *sockets);
void    initializeAddress(t_address *address, int port);
void    initializeFdSet(t_fdSet *fdSet, int serverSocket);
void    makeServerSocketListen(int socket, struct sockaddr_in address);
void    makeChattingLoop(t_server *server);
void    acceptClient(t_server *server);
t_client	*makeClient(t_server *server);
void	addClient(t_client **clientList, t_client *newClient);
void	receiveClientMessage(t_server *server);
void	removeClient(t_server *server);
void	sendMessage(char *message, t_server *server);

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
        handleError("Wrong number of arguments", NULL);
}

void    initializeServer(t_server *server, int port) {
    initializeSocket(&server->socket);
    initializeAddress(&server->address, port);
    initializeFdSet(&server->fdSet, server->socket.server);
	server->clientList = NULL;
	server->lastClientId = -1;
}

void    initializeSocket(t_socket *sockets) {
    sockets->server = socket(PF_INET, SOCK_STREAM, 0);
    if(sockets->server == -1)
        handleError("Fatal error", NULL);
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

void    initializeFdSet(t_fdSet *fdSet, int serverSocket) {
    FD_ZERO(&fdSet->origin);
    FD_SET(serverSocket, &fdSet->origin);
}

void    makeServerSocketListen(int socket, struct sockaddr_in address) {
    if (bind(socket, &address, sizeof(address)) == -1)
        handleError("Fatal error", NULL);
    if (listen(socket, 10) == -1)
        handleError("Fatal error", NULL);
}

void    makeChattingLoop(t_server *server) {
    int     numberOfSelectedFds;

    while (1) {
        numberOfSelectedFds = 
            select(server->socket.max + 1, &server->fdSet.read, &server->fdSet.write, 0, 0);
        if (numberOfSelectedFds)
            responseFromSelectedFds(server);
    }
} 

void    responseFromSelectedFds(t_server *server) {
    int i;

    for (i = 0; i < server->socket.max; i++) {
        if (FD_ISSET(i, &server->fdSet.read)) {
            if (i == server->socket.server)
                acceptClient(server);
			else {
				server->socket.client = i;
				receiveClientMessage(server);
			}
        }
    }
}

void    acceptClient(t_server *server) {
	int			stringSize;
    t_client    *newClient;
	char		buffer[1000];

    server->socket.client = 
        accept(server->socket.server, (struct sockaddr *) &server->address.client, &server->address.size);
    FD_SET(server->socket.client, &server->fdSet.origin);
    if (server->socket.client > server->socket.max)
        server->socket.max = server->socket.client;
	newClient = makeClient(server);
	addClient(&server->clientList, newClient);
	sprintf(buffer, "server: client %d just arrived\n", newClient->id);
	sendMessage(server, newClient->id);
}

t_client	*makeClient(t_server *server) {
	t_client	*newClient;

	newClient = (t_client *) malloc(sizeof(t_client));
	newClient->socket = server->socket.client;
	newClient->id = ++(server->lastClientId);
	newClient->next = NULL;
	newClient->prev = NULL;
	if (!newClient)
		handleError("Fatal error", NULL);
	return (newClient);
}

void	addClient(t_client **clientList, t_client *newClient) {
	t_client	*copyList;

	if (*clientList == NULL)
		*clientList = newClient;
	else {
		copyList = *clientList;
		while (copyList->next)
			copyList = copyList->next;
		copyList->next = newClient;
		newClient->prev = copyList;
	}
}

void	receiveClientMessage(t_server *server) {
	char	*clientMessage;
	char	buffer[BUFFER_SIZE];
	int		readSize;

	readSize = recv(server->socket.client, buffer, BUFFER_SIZE - 1, 0);
	buffer[readSize] = '\0';
	if (readSize == 0) 
		removeClient(server);
	else  {
		clientMessage = getClientMessage(server);
	}
}

void	removeClient(t_server *server) {
	t_client	*client;
	char		buffer[BUFFER_SIZE];
	int			clientSocket = server->socket.client;

	client = server->clientList;
	while (client && client->socket != clientSocket)
		client = client->next;
	if (client->prev)
		client->prev->next = client->next;
	if (client->next)
		client->next->prev = client->prev;
	if (client == server->clientList)
		server->clientList = client->next;
	if (clientSocket == server->socket.max)
		server->socket.max = getSocketMax(server);
	sprintf(buffer, "server: client %d just left\n", client->id);
	FD_CLR(clientSocket, &server->fdSet.origin);
	close(clientSocket);
	free(client);
	client = NULL;
}

int	getSocketMax(t_server *server) {
	int			max = server->socket.server;
	t_client	*client;

	client = server->clientList;	
	while (client) {
		if (client->socket > max)
			max = client->socket;
		client = client->next;
	}
	return (max);
}

void	getClientMessage(t_server *server, char *buffer) {
	char	*clientMessage;
	char	*temp;
	int		recvSize;

	clientMessage = (char *) malloc(sizeof(char) * strlen(buffer) + 1);
	if (!clientMessage)
		handleError("Fatal error", server);
	bzero(buffer, BUFFER_SIZE);
	recvSize = recv(server->socket.client, buffer, BUFFER_SIZE - 1, 0);
	buffer[recvSize] = '\0';
	while (recvSize) {
		temp = clientMessage;
		clientMessage = ft_strjoin(clientMessage, buffer);
	}
}

char	*ft_strjoin(char *string1, char *string2) {
	char	*joinedString;
	int		size = strlen(string1) + strlen(string2);

	joinedString = (char *) malloc(sizeof(char) * size + 1);
	if (!joinedString)	
		return (NULL);
}

void	sendMessage(char *message, t_server *server) {
	int	i;

	for (i = 0; i < server->socket.max + 1; i++) {
		if (FD_ISSET(i, &server->fdSet.write)) {
			if (i != server->socket.server && i != server->socket.client)
				send(i, server->buffer, strlen(server->buffer), 0);
		}
	}
}

void    handleError(char *message, t_server *server) {
	if (server)
		freeAllocatedData(server);
    write(STDERR_FILENO, message, strlen(message));
    write(STDERR_FILENO, '\n', 1);
    exit(1);
}

void	freeAllocatedData(t_server *server) {
	t_client	*client = server->clientList;
	t_client	*temp;

	while (client) {
		temp = client;
		client = client->next;
		free(temp);
		temp = NULL;
	}
	server->clientList = NULL;
}