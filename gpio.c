/*
 * gpio.c
 *
 *  Created on: Feb 24, 2016
 *      Author: nick
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <stdint.h>

#include "AB2016.h"
#include "gpio.h"

void GPIO_export(int);
void GPIO_unexport(int);
void GPIO_setDirection(const char*, int);
void GPIO_setValue(const char*, int);
void GPIO_setEdge(const char*);
int GPIO_poll(const char*);

int fd;
char GPIObuf[64];

void GPIO_export(int gpio) {
	fd = open("/sys/class/gpio/export", O_WRONLY);
	sprintf(GPIObuf, "%d", gpio);
	write(fd, GPIObuf, 1);
	close(fd);
}

void GPIO_unexport(int gpio){

	fd = open("/sys/class/gpio/unexport", O_WRONLY);
	sprintf(GPIObuf, "%d", gpio);
	write(fd, GPIObuf, 1);
	close(fd);
}

void GPIO_setDirection(const char *port, int direction) {

	sprintf(GPIObuf, "/sys/class/gpio/%s/direction", port);
	fd=open(GPIObuf, O_WRONLY);

	if (direction == 0)
		write(fd, "out", 3);
	else
		write(fd, "in", 2);

	close(fd);
}

void GPIO_setValue(const char *port, int value){

	sprintf(GPIObuf, "/sys/class/gpio/%s/value", port);
	fd=open(GPIObuf, O_WRONLY);

	if (value == 1)
		write(fd, "1", 1);
	else
		write(fd, "0", 1);
	close(fd);
}

void GPIO_setEdge(const char *port) {

	sprintf(GPIObuf, "/sys/class/gpio/%s/edge", port);
	fd=open(GPIObuf, O_WRONLY);
	write(fd, "falling", 7);
	debug("path: %s\r\n", GPIObuf);
	close(fd);

}

int GPIO_poll(const char *port) {

	struct pollfd fds;
	int pollRet;
	char *readValue = "";

	sprintf(GPIObuf, "/sys/class/gpio/%s/value", port);
	debug ("Opening %s\r\n", GPIObuf);
	fd=open(GPIObuf, O_RDONLY);

	if (fd < 0)
		printf("Failed, gpio not exported\r\n");

	fds.fd = fd;
	fds.events = POLLPRI;

	debug("Before Poll: %s\r\n", GPIObuf);

	lseek(fd, 0, SEEK_SET);
	read(fd, readValue, 1);

	pollRet = poll(&fds, 1, -1);

	lseek(fd, 0, SEEK_SET);
	read(fd, readValue, 1);

	debug("After Poll: %d\r\n", fds.revents);

	close(fd);

	return pollRet;

}
