#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <poll.h>
#include <stdint.h>
#include <signal.h>
#include <sys/time.h>
#include <errno.h>

#include "AB2016.h"
#include "gpio.h"

double AD_poll(const char *channel, uint8_t);


extern void GPIO_export(int);
extern void GPIO_unexport(int);
extern void GPIO_setDirection(const char*, int);
extern void GPIO_setValue(const char*, int);
extern void GPIO_setEdge(const char*);
extern int GPIO_poll(const char*);

extern void timer_handler(void);

extern int SPI_init(char[]);
extern void SPI_close(int);//	fp = SPI_init(device);
//	printf ("SPI_init fp: %d \r\n", fp);

extern int SPI_transfer(int, uint8_t[]);
extern int TCP_openSocket(void);
extern int TCP_Send(int, char *);
extern int serial_Send(char[]);


char GPIObuf[64];
int fd, TCPsock;
double Vref = 0;

uint8_t maxReadings = 32;

#define IN	1
#define OUT 0


double AD_poll(const char *channel, uint8_t readVref) {

	char readValue[] = "";
	uint32_t raw = 0;
	uint32_t rawAve = 0;
	double v;
	uint8_t readCount;

	fd=open(channel, O_RDONLY | O_NONBLOCK);

	if (fd < 0)
		perror("Failed,couldn't open ADC channel for reading\r\n");

	if (readVref) {

		read(fd, readValue, 4);

		if (readValue != NULL) // Prevents a segfault
				Vref = atof(readValue);

		debug("Vref: %.2f\r\n", Vref);

		return 0;
	}

	else {

		for (readCount = 0; readCount < maxReadings; readCount++) {

			read(fd, readValue, 4);

			if (readValue != NULL) // Prevents a segfault
				raw = raw + atof(readValue);
		}

		rawAve = raw / maxReadings;
		v = (Vref / 1024) * rawAve;
	}

	close(fd);
	return v;
}



int main(void) {

	int fp, ret;
	char device[] = "/dev/spidev32765.0";
	char uartdev[] = "/dev/ttyS1";
	char TXdata[64];

	char ADchannel[] = "/sys/bus/iio/devices/iio:device0/in_voltage4_raw";
	char ADreference[] = "/sys/bus/iio/devices/iio:device0/in_voltage_scale";

	char *value;

	double Vread, v;

	uint8_t txArray[8] = {0x55, 0x5a, 0x49, 0x55, 0x66, 0x06, 0x35, 0x65};

	char message[] = "Right Back Atcha!";

//	printf("HELLO! Talking to %s\r\n", device);

// Export and configure all GPIOs here
	GPIO_export(A0);
	GPIO_export(A1);

	GPIO_setDirection(testled, OUT);
	GPIO_setDirection(testint, IN);

	GPIO_setEdge(testint);


// Initialize serial ports here
	serialInit(uartdev);

// Initialize SPIs here
	//	fp = SPI_init(device);
	//	printf ("SPI_init fp: %d \r\n", fp);


// Setup timers here
	struct sigaction sa;
	struct itimerval timer;

	 /* Install timer_handler as the signal handler for SIGVTALRM. */
	 memset (&sa, 0, sizeof (sa));
	 sa.sa_handler = &timer_handler;
	 sigaction (SIGALRM, &sa, NULL);

	 /* Configure the timer to expire after 250 msec... */
	 timer.it_value.tv_sec = 1;
	 timer.it_value.tv_usec = 0;
	 /* ... and every 250 msec after that. */
	 timer.it_interval.tv_sec = 1;
	 timer.it_interval.tv_usec = 0;
	 setitimer (ITIMER_REAL, &timer, NULL);


//	ret = SPI_transfer(fp, txArray);
//	printf ("SPI_transfer ret: %d \r\n", ret);
//	SPI_close(fp);


	printf("HELLO! Opening a TCP socket\r\n");

//	TCPclient();
	TCPsock = TCP_openSocket();

	AD_poll(ADreference, 1);

	while(1) {
		sleep(1);
		Vread = AD_poll(ADchannel, 0);
//		printf("Voltage: %.2f\r\n", Vread);
		printf("Received: %c\r\n", rx2);
		serial_Send(message);

		if (TCPsock != -1) {
			sprintf(TXdata, "%.2f", Vread);
			TCP_Send(TCPsock, TXdata);
		}
	}

//	poll = GPIO_poll(testint);

//	GPIO_setValue(testled, 1);
//	debug("GPIO Poll Return: %d\r\n", poll);
//	sleep(1);
//	GPIO_setValue(testled, 0);


// Unexport all GPIOs here
	GPIO_unexport(A0);
	GPIO_unexport(A1);

	return 0;
}
