#include <stdio.h>
#include <string.h>

int	main(void) {
	char	string[10];
	char	*example1 = "abcd";
	char	*example2 = "ggggg";

	strcpy(string, example1);
	printf("string: %s\n", string);
	strcat(string, example2);
	return (0);
}