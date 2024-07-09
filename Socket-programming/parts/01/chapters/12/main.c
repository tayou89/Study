#include <stdio.h>

int main(void) {
    char    buffer[20];
    int     sprintfReturn;

    sprintfReturn = sprintf(buffer, "Hello, %s", "world");
    printf("springfReturn: %d\n", sprintfReturn);
    printf("buffer: %s\n", buffer);
    return (0);
}