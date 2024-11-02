#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t client_len = sizeof(client_addr);

    // Create UDP socket
    if ((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    // Server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to server address
    if (bind(server_fd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("UDP Server listening on port %d...\n", PORT);

    while (1) {
        // Receive message from client
        int n = recvfrom(server_fd, (char *)buffer, BUFFER_SIZE, MSG_WAITALL,
                        (struct sockaddr *)&client_addr, &client_len);
        buffer[n] = '\0';
        printf("Client: %s\n", buffer);

        // Send response back to client
        char *response = "Hello from UDP server!";
        sendto(server_fd, (const char *)response, strlen(response), MSG_CONFIRM,
               (const struct sockaddr *)&client_addr, client_len);
        printf("Response sent to client\n");
    }

    return 0;
}
