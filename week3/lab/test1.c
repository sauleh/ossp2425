#include <arpa/inet.h>
#include <stdio.h>


unsigned int revbytes(unsigned int n)
{
    
}

int main()
{
    struct sockaddr_in serv_addr1;
    struct sockaddr_in serv_addr2;
    inet_pton(AF_INET, "194.126.2.2", &serv_addr1.sin_addr);
    inet_pton(AF_INET, "194.125.254.2", &serv_addr2.sin_addr);
    // unsigned char pch = 0xff & serv_addr.sin_addr.s_addr; 
    printf("%x\n", serv_addr1.sin_addr.s_addr);
    printf("%x\n", serv_addr2.sin_addr.s_addr);
    // serv_addr.sin_addr.s_addr >>= 8;


}