// server.c
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

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("usage: ./a.out -i\n./a.out <port>\n");
        return -1;
    }
    
    char buf[BUFSIZE]; memset(buf, BUFSIZ, 0);
    int inHandle = STDIN_FILENO, outHandle = STDOUT_FILENO;
    int server_fd = -1, new_socket = -1;
    if (strcmp(argv[1], "-i") == 0)
    {
        get_client_socket(&server_fd, &new_socket);
        outHandle = inHandle = new_socket;
    }
    
    
    int len = read(inHandle, buf, BUFSIZE); // Read from STDIN or SOCKET
    write(outHandle, buf, len);             // Write to STDOUT or SOCKET

    if (new_socket != -1)
        close(new_socket);
    
    if (server_fd != -1)
        close(server_fd);

    return 0;
}
