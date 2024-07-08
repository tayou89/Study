#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) 
{
    char            *addr1 = "1.2.3.4";
    char            *addr2 = "1.2.3.256";
    unsigned long   convertedAddress = inet_addr(addr1);

    if (convertedAddress == INADDR_NONE)
        printf("Error occured!\n");
    else
        printf("Network ordered integer addr: %#lx \n", convertedAddress);

    convertedAddress = inet_addr(addr2);
    if (convertedAddress == INADDR_NONE)
        printf("Error occured!\n");
    else
        printf("Network ordered integer addr: %#lx \n", convertedAddress);
    return (0);
}