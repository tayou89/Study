#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/select.h>
#include <stdio.h>

#define BUFFER_SIZE	42 * 4096	
#define CLIENTS_MAX  1024

typedef struct s_request {
	int		socket;
	int		id;
	char	message[BUFFER_SIZE];
}	t_request;

typedef struct s_server {
    int 				socket;
    int					fdMax;
    int					clientIds[CLIENTS_MAX];
    int					lastClientId;
	fd_set				fdSet;
	struct sockaddr_in	address;
	t_request			request;
}   t_server;

void    			checkArgumentCount(int count);
void				setServer(t_server *server, int port);
int					getServerSocket(void);
fd_set				getServerFdSet(int socket);
struct sockaddr_in	getServerAddress(int port);
void    			makeServerSocketListen(int socket, struct sockaddr_in address);
void    			makeChattingLoop(t_server *server);
void    			response(t_server *server, fd_set readSet);
void    			acceptClient(t_server *server);
void				receiveRequestMessage(t_server *server);
void				removeClient(int clientSocket, t_server *server);
int					getNewSocketMax(int prevMax, fd_set fdSet);
void				sendClientMessage(t_server *server);
void				sendMessage(char *message, int ignoreFd, t_server server); 
void				handleError(char *message);
void				freeRequestMessage(t_server *server);

int main(int argc, char *argv[]) {
    t_server    server;

    checkArgumentCount(argc);
    setServer(&server, atoi(argv[1]));
    makeChattingLoop(&server);
	close(server.socket);
    return (0);
}

void    checkArgumentCount(int count) {
    if (count < 2)
        handleError("Wrong number of arguments");
}

void    setServer(t_server *server, int port) {
	server->socket = getServerSocket();
	server->fdSet = getServerFdSet(server->socket);
	server->fdMax = server->socket;
	server->address = getServerAddress(port);
	makeServerSocketListen(server->socket, server->address);
	server->lastClientId = -1;
	server->request.socket = -1;
	server->request.id = -1;
	bzero(server->request.message, sizeof(server->request.message));
}

int	getServerSocket(void) {
	int serverSocket;

	serverSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1)
		handleError("Fatal error");
	return (serverSocket);
}

fd_set	getServerFdSet(int socket) {
	fd_set	fdSet;

	FD_ZERO(&fdSet);
	FD_SET(socket, &fdSet);
	return (fdSet);
}

struct sockaddr_in	getServerAddress(int port) {
	struct sockaddr_in	address;

	memset(&address, 0, sizeof(address));
	address.sin_family = PF_INET;
	address.sin_addr.s_addr = htonl(INADDR_LOOPBACK); address.sin_port = htons(port);
	return (address);
}

void    makeServerSocketListen(int socket, struct sockaddr_in address) {
    if (bind(socket, (struct sockaddr *) &address, sizeof(address)) == -1)
        handleError("Fatal error");
    if (listen(socket, 100) == -1)
        handleError("Fatal error");
}

void    makeChattingLoop(t_server *server) {
    int		fdCount = 0;
	fd_set	readSet;

    while (1) {
		readSet = server->fdSet;
        fdCount = select(server->fdMax + 1, &readSet, 0, 0, 0);
        if (fdCount)
            response(server, readSet);
    }
} 

void    response(t_server *server, fd_set readSet) {
    int 	i;

    for (i = 0; i < server->fdMax + 1; i++) {
        if (FD_ISSET(i, &readSet)) {
            if (i == server->socket)
                acceptClient(server);
			else  {
				printf("It's not a server socket\n");
				server->request.socket = i;
				server->request.id = server->clientIds[i];
				receiveRequestMessage(server);
				sendClientMessage(server);
			}
        }
    }
}

void    acceptClient(t_server *server) {
	char	buffer[BUFFER_SIZE];
    int     clientSocket;

    clientSocket = accept(server->socket, NULL, NULL);
    FD_SET(clientSocket, &server->fdSet);
    if (clientSocket > server->fdMax)
        server->fdMax = clientSocket;
	server->clientIds[clientSocket] = server->lastClientId + 1;
	server->lastClientId = server->clientIds[clientSocket];
	sprintf(buffer, "server: client %d just arrived\n", server->clientIds[clientSocket]);
	printf("%s", buffer);
	sendMessage(buffer, clientSocket, *server);
}

void	receiveRequestMessage(t_server *server) {
	char	buffer[BUFFER_SIZE - 1];
	int		readSize;

	printf("receiveRequestMessage() called\n");
	readSize = recv(server->request.socket, buffer, BUFFER_SIZE - 1, 0);
	if (readSize == -1)	
		return ;
	buffer[readSize] = '\0';
	if (readSize == 0) 
		removeClient(server->request.socket, server);
	strcpy(server->request.message, buffer);
}

void	sendClientMessage(t_server *server) {
	char	messageLine[strlen(server->request.message) + 1];
	char	*buffer;
	char	*start = server->request.message;
	char	*end = start + strlen(start);
	char	*newLine = NULL;

	bzero(messageLine, sizeof(messageLine));
	while (*start != '\0') {
		newLine = strstr(start, "\n");
		if (newLine)
			end = newLine + 1;
		else
			end = start + strlen(start);
		strcpy(messageLine, start);
		messageLine[end - start] = '\0';
		buffer = (char *) malloc(strlen(messageLine) + 100);
		if (!buffer) 
			handleError("Fatal error");
		sprintf(buffer, "client %d: %s", server->request.id, server->request.message);
		printf("%s", buffer);
		sendMessage(buffer, server->request.socket, *server);
		free(buffer);
		buffer = NULL;
		start = end + 1;
	}
	bzero(server->request.message, sizeof(server->request.message));
}

void	removeClient(int clientSocket, t_server *server) {
	char		buffer[BUFFER_SIZE];

	FD_CLR(clientSocket, &server->fdSet);
	close(clientSocket);
	if (clientSocket == server->fdMax)
		server->fdMax = getNewSocketMax(clientSocket, server->fdSet);
	sprintf(buffer, "server: client %d just left\n", server->clientIds[clientSocket]);
	printf("%s", buffer);
	sendMessage(buffer, clientSocket, *server);
}

int	getNewSocketMax(int prevMax, fd_set fdSet) {
	int		max = 0;
	int		i;

	for (i = 0; i < prevMax; i++) {
		if (FD_ISSET(i, &fdSet) && i > max)
			max = i;
	}
	return (max);
}



void	sendMessage(char *message, int ignoreFd, t_server server) {
	fd_set			writeSet = server.fdSet;
	struct timeval	timeout;
	int	i;

	timeout.tv_sec = 0;
	timeout.tv_usec = 0;
	select(server.fdMax + 1, 0, &writeSet, 0, &timeout);
	for (i = 0; i < server.fdMax + 1; i++) {
		if (FD_ISSET(i, &writeSet)) {
			if (i != server.socket && i != ignoreFd)
				send(i, message, strlen(message), 0);
		}
	}
}

void    handleError(char *message) {
    write(STDERR_FILENO, message, strlen(message));
    write(STDERR_FILENO, "\n", 1);
    exit(1);
}