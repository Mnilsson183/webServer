#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void){
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1){
        printf("The server was unable to start the socket");
        return -1;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = 
    serverAddr.sin_addr
    serverAddr.zero[8];

    
}