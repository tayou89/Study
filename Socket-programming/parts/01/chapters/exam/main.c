#include <string.h>
#include <stdio.h>

int	main(void) {
	char	buffer[100];
	char	*string1 = NULL;
	char	*string2 = "abcd";

	bzero(buffer, sizeof(buffer));
	strcpy(buffer, string1);
	strcat(buffer, string2);
	printf("buffer: %s\n", buffer);
	return (0);
}