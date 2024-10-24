#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZE];
    memset(buffer, BUFSIZE, 0);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    char buf[BUFSIZE];    
    fgets(buf, BUFSIZE, stdin);
    write(sock, buf, strlen(buf));
    read(sock, buf, BUFSIZE);
    fprintf(stdout, "server: %s\n", buf);
    close(sock);
    return 0;
}