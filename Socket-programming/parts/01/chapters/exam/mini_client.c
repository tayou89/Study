#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE	1024

void	checkArgumentCount(int count);
void	handleError(char *errorMessage);
char	*ft_strjoin(char *string1, char *string2);

int	main(int argc, char *argv[]) {
	int					clientSocket;
	int					readSize;
	char				*input = NULL;
	char				*temp = NULL;
	fd_set				fdSet;
	fd_set				readSet;
	struct sockaddr_in	address;
	char				buffer[BUFFER_SIZE];

	checkArgumentCount(argc);
	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (clientSocket == -1)	
		handleError("socket() error");
	address.sin_family = PF_INET;
	address.sin_addr.s_addr = inet_addr(argv[1]);
	address.sin_port = htons(atoi(argv[2]));
	if (connect(clientSocket, (struct sockaddr *) &address, sizeof(address)) == -1)
		handleError("connect() error"); 
	printf("Succefully connected to %s:%s\n", argv[1], argv[2]);
	// fcntl(clientSocket, F_SETFL, O_NONBLOCK);
	// fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
	FD_ZERO(&fdSet);
	FD_SET(STDIN_FILENO, &fdSet);
	FD_SET(clientSocket, &fdSet);
	while (1) {
		readSet = fdSet;
		select(clientSocket + 1, &readSet, 0, 0, 0);
		if (FD_ISSET(STDIN_FILENO, &readSet)) {
			readSize = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
			buffer[readSize] = '\0';
			while (readSize) {
				temp = input;
				input = ft_strjoin(input, buffer);
				if (!input) {
					free(temp);
					temp = NULL;
					handleError("ft_strjoin() error");
				}
				if (temp) {
					free(temp);
					temp = NULL;
				}
				readSize = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
				printf("readSize: %d\n", readSize);
				buffer[readSize] = '\0';
			}
			send(clientSocket, input, strlen(input), 0);
			free(input);
			input = NULL;
		}
		if (FD_ISSET(clientSocket, &readSet)) {
			readSize = recv(clientSocket, buffer, BUFFER_SIZE - 1, 0);
			if (readSize == 0) {
				printf("Server disconnected!\n");
				break ;
			}
			buffer[readSize] = '\0';
			while (readSize) {
				temp = input;
				input = ft_strjoin(input, buffer);
				if (!input) {
					free(temp);
					temp = NULL;
					handleError("ft_strjoin() error");
				}
				if (temp) {
					free(temp);
					temp = NULL;
				}
				readSize = recv(clientSocket, buffer, BUFFER_SIZE - 1, 0);
				buffer[readSize] = '\0';
			}
			printf("%s", input);
			free(input);
			input = NULL;
		}
	}
	close(clientSocket);
	return (0);
}

void	checkArgumentCount(int count) {
	if (count != 3)
		handleError("Wrong Arguments");
}

void	handleError(char *errorMessage) {
	write(STDERR_FILENO, errorMessage, strlen(errorMessage));
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}

char	*ft_strjoin(char *string1, char *string2) {
	char	*joinedString;
	int		size;

	if (string1 == NULL) {
		size = strlen(string2);
		joinedString = (char *) malloc(size + 1);
		strcpy(joinedString, string2);
		joinedString[size] = '\0';
		return (joinedString);
	}
	size = strlen(string1) + strlen(string2);
	joinedString = (char *) malloc(size + 1);
	if (!joinedString)
		return (NULL);
	strcpy(joinedString, string1);
	strcat(joinedString, string2);
	joinedString[size] = '\0';
	return (joinedString);
}