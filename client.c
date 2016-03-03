#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <errno.h>

#include <pthread.h>

#include "AB2016.h"

//int TCPclient(void);
int TCP_openSocket(void);
void TCP_Get(void);
int TCP_Send(int, char *data[]);

static int sock2;

//int TCPclient(void)
int TCP_openSocket(void)
{
    int sock, error;
    struct sockaddr_in server;
    pthread_t tid;

 //   char message[1000] , server_reply[2000];

 //   strcpy(message, "Thank You for accepting my connection!\r\n");

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
    sock2 = sock;

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return -1;
    }

    puts("Connected\n");

 // Setup a thread to handle incoming data
    error = pthread_create(&tid, NULL, &TCP_Get, NULL);

    if (error != 0)
    	perror("Could not create thread: \r\n");

    return sock;
}

int TCP_Send(int sock, char *data[]) {


        if( send(sock , data , strlen(data) , 0) < 0)
        {
            perror("Send failed");
            return 1;
        }

    return 0;
}


void TCP_Get(void) {

	char reply[2000];

	while(1) {

       if( recv(sock2 , reply , 2000 , 0) < 0)
       {
           perror("recv failed");
       }
      puts("Server reply :");
      puts(reply);
   }

}
