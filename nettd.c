#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>

void receive(int port);

int main(int argc, char **argv)
{
    if(argc != 3){
        printf("Invalid ammount of input arguments.\n");
        return 1;
    }
    
    if(strcmp(argv[1], "receive") != 0){
        printf("Invalid mode (usage: nettd receive [portnr]).\n");
        return 1;
    }
    
    if(strcmp(argv[1], "receive") == 0){
        receive(atoi(argv[2]));
    }
    
    return 0;
}

void receive(int port)
{
    int sock, clientsocket, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock < 0) {
        perror("Could not open socket");
        exit(1);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    
    if (bind(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Could not bild to port");
        exit(1);
    }

    listen(sock, 5);
    clilen = sizeof(cli_addr);
    
    int n;
    clientsocket = accept(sock, (struct sockaddr *)&cli_addr, &clilen);
        
    if (clientsocket < 0) {
        perror("Could not accept client");
        exit(1);
    }

    char buffer[256];
    bzero(buffer, 256);

    while (n = read(clientsocket, buffer, 255) > 0){   
            printf("%s", buffer);
    }
   
}