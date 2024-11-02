#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create UDP socket
    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    // Server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Send message to server
    char *message = "Hello from UDP client!";
    sendto(sock_fd, (const char *)message, strlen(message), MSG_CONFIRM,
           (const struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("Message sent to server\n");

    // Receive server's response
    socklen_t server_len = sizeof(server_addr);
    int n = recvfrom(sock_fd, (char *)buffer, BUFFER_SIZE, MSG_WAITALL,
                     (struct sockaddr *)&server_addr, &server_len);
    buffer[n] = '\0';
    printf("Server: %s\n", buffer);

    close(sock_fd);
    return 0;
} 
