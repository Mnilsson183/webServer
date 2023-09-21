#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define PORT 8080

char resp[] = "HTTP/1.0 200 OK\r\n"
            "Server: webserver-c\r\n"
            "Content-type: text/html\r\n\r\n"
            "<html>hello, world</html>\r\n";



int main(void){
    // create the server socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1){
        perror("The server was unable to start the socket");
        exit(EXIT_FAILURE);
    }
    printf("\nSocket created successfully\n");

    // set up the server addr 
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
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
    printf("Server listening for connections on port %d\n", PORT);

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
        // todo
        // for now just give default web page
        int contentLength = sizeof(resp);

        // serve web page from file
        // FILE *file = fopen("~/Desktop/webServer/content/web.html", "r");
        // if (file == NULL){
        //     perror("The web page to serve was not found");
        //     return -1;
        // }
        // char responseHeader[1024];
        // sprintf(responseHeader, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", contentLength);
        // send(clientSocket, sizeof(responseHeader), strlen(responseHeader), 0);

        // char buffer[1024];
        // while( fgets(buffer, sizeof(buffer),resp) != NULL){
        //     send(clientSocket, buffer, strlen(buffer), 0);
        // }
        send(clientSocket, resp, strlen(resp), 0);

        // close the client connection
        close(clientSocket);

        // close the server
        close(serverSocket);

        // kill socket on sys
        setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, true, sizeof(int));

        return 0;
    }
}

void *handle_client(void *arg){
    
}