#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void){
    // create the server socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1){
        perror("The server was unable to start the socket");
        exit(EXIT_FAILURE);
    }
    printf("Socket created successfully\n");

    // set up the server addr 
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // bind together the socket and the addr
    if (bind(serverSocket, (struct serverAddr *)&serverAddr, sizeof(serverAddr))){
        perror("The address was unable to bind the server");
        exit(EXIT_FAILURE);
    }
    printf("The Address was successfully bound\n");

    // began to listen for client connections
    if (listen(serverSocket, 5) == -1){
        perror("The server was unable to listen");
        exit(EXIT_FAILURE);
    }
    printf("Server listening for connections\n");

    //allow a client connection
    int clientSocket;
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);

    while(true){
        clientSocket = accept(serverSocket, (struct serverAddr *)&serverAddr, sizeof(serverAddr));
        if (clientSocket == -1){
            perror("The server was unable to accept a client connection");
            exit(EXIT_FAILURE);
        }
        printf("Connection Accepted\n");

        // parse the http request


        int contentLength;

        // serve web page
        FILE *file = fopen("~/Desktop/webServer", "r");
        if (file == NULL){
            perror("The web page to serve was not found");
            return -1;
        }

        char responseHeader[1024];
        sprintf(responseHeader, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", contentLength);
        send(clientSocket, sizeof(responseHeader), strlen(responseHeader), 0);

        char buffer[1024];
        while( fgets(buffer, sizeof(buffer),file) != NULL){
            send(clientSocket, buffer, strlen(buffer), 0);
        }

    }
    // close the client connection
    close(clientSocket);

    // close the server
    close(serverSocket);
}

void *handle_client(void *arg){
    
}