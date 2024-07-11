#include <stdio.h>
#include <string.h>

int	main(void) {
	char	string[10];
	char	*example1 = "abcdefghijk";
	// char	*example2 = "ggggg";

	strcpy(string, example1);
	string[sizeof(string) - 1] = '\0';
	printf("string: %s\n", string);
	// strcat(string, example2);
	// printf("string: %s\n", string);
	return (0);
}