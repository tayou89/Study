#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE    30

int main(int argc, char *argv[])
{
    fd_set          reads;
    fd_set          temps;
    int             result;
    int             stringLength;
    char            buf[BUF_SIZE];
    struct timeval  timeout;

    FD_ZERO(&reads);
    FD_SET(0, &reads);

    while (1) 
    {
        temps = reads;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        result = select(1, &temps, 0, 0, &timeout);
        if (result == -1)
        {
            puts("select() error");
            break ;
        }
        else if (result == 0)
            puts("Time-out!");
        else
        {
            if (FD_ISSET(0, &temps))
            {
                stringLength = read(0, buf, BUF_SIZE);
                buf[stringLength] = '\0';
                printf("message from console: %s", buf);
            }
        }
    }
    return (0);
}