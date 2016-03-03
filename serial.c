/*
 * serial.c
 *
 *  Created on: Feb 23, 2016
 *      Author: nick
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/signal.h>
#include <errno.h>
#include <termios.h>
#include <pthread.h>

#include "AB2016.h"

void serial_Get(void);
void serial_Send(char *);

int n, charCount;
static int fd;
int connected;
struct termios termAttr;
struct sigaction saio;
char rxData[32];

int serialInit(char device[])
{

    pthread_t tid;
    int error;

 //    fd = open(device, O_RDWR | O_NOCTTY | O_NDELAY);
     fd = open(device, O_RDWR);
     if (fd == -1) {
        perror("open_port: Unable to open serial port");
        return fd;
     }

     tcgetattr(fd,&termAttr);

     cfsetispeed(&termAttr,B115200);
     cfsetospeed(&termAttr,B115200);
     termAttr.c_cflag &= ~PARENB;
     termAttr.c_cflag &= ~CSTOPB;
     termAttr.c_cflag &= ~CSIZE;
     termAttr.c_cflag |= CS8;
     termAttr.c_cflag |= (CLOCAL | CREAD);
     termAttr.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
     termAttr.c_iflag &= ~(IXON | IXOFF | IXANY);
     termAttr.c_oflag &= ~OPOST;

     tcsetattr(fd,TCSANOW,&termAttr);
     debug("UART1 configured....\n");

// Start a thread that waits for incoming serial data
     error = pthread_create(&tid, NULL, &serial_Get, NULL);

     if (error != 0)
     	perror("Could not create thread: \r\n");

  }

void serial_Get()
  {
	  int bytes;

	  while(1) {

		  bytes = read(fd, &rx, 1);

		  if (bytes < 0)
			  perror("Read Error: \r\n");
		  else
			  printf("Bytes: %d	received data from UART: %c\r\n", bytes, rx);

		  rx2 = rx;
	  }
  }

void serial_Send(char *data) {

	int bytes;
	printf("Sending %s\r\n", data);
	bytes = write(fd, data, strlen(data));

	 if (bytes < 0)
		 perror("Write Error: \r\n");
	 else
		 printf("Bytes Written to fd %d:	%d\r\n", fd, bytes);
}

