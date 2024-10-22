// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char *message = "Hello from server";

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Bind socket to port 8080
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    // Listen for incoming connections
    listen(server_fd, 3);
    // Accept a connection
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    // Send message to the client
    send(new_socket, message, strlen(message), 0);

    close(new_socket);
    close(server_fd);
    return 0;
}
