#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

void get_client_socket(int* server_fd, int* new_socket)
{
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    *server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    bind(*server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(*server_fd, 3);
    *new_socket = accept(*server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
}


int main()
{
    int server_fd=-1, new_socket=-1;


    char buf[BUFSIZE]; memset(buf, BUFSIZE, 0);
    int inHandle = STDIN_FILENO, outHandle = STDOUT_FILENO;
    if (1)
    {
        get_client_socket(&server_fd, &new_socket);
        inHandle = outHandle = new_socket;
    }

    int len = read(inHandle, buf, BUFSIZE);
    for(int i=0; i<len-1; i++)
        buf[i] -= ('a' - 'A');

    write(outHandle, buf, len);
}