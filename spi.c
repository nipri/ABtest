#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

int SPI_init(char[]);
void SPI_close(int);
int SPI_transfer(int, uint8_t[]);


int SPI_init(char device[]) {

	int ret = 0;
	int fp;

	int mode = 3;
	int bits = 8;
	double speed = 100000;
	double delay = 1000000;

	printf("OPENING %s\r\n", device);

	fp = open(device, O_RDWR);

	if (fp < 0) {
		perror("Open SPI device failed");
		return 0;
	}
	printf ("fp: %d \r\n", fp);
//  set CPOL and CPHA
	ret = ioctl(fp, SPI_IOC_WR_MODE, &mode);

	if (ret == -1) {
		perror("Can't set SPI Write Mode");
		return 0;
	}

	ret = ioctl(fp, SPI_IOC_RD_MODE, &mode);

	if (ret == -1) {
		perror("Can't set SPI Read Mode");
		return 0;
	}

//  set number of bits / word
	ret = ioctl(fp, SPI_IOC_WR_BITS_PER_WORD, &bits);

	if (ret == -1) {
		perror("Can't set SPI Bits Per Word");
		return 0;
	}

//  set max speed in Hz
	ret = ioctl(fp, SPI_IOC_WR_MAX_SPEED_HZ, &speed);

	if (ret == -1) {
		perror("Can't set SPI Max Speed");
		return 0;
	}

	return fp;
}

void SPI_close(int fp) {
	printf("Closing %d\r\n", fp);
	close(fp);
}

int SPI_transfer(int fp, uint8_t txData[]) {

	int ret;
	int rxData[8] = {0, };

	struct spi_ioc_transfer tr = {
			.tx_buf = (unsigned long)txData,
			.rx_buf = (int)rxData,
			.len = 8,
			.delay_usecs = 0,
//			.speed_hz = 1000000,
			.bits_per_word = 8,
			.cs_change=0,
	};

	ret = ioctl(fp, SPI_IOC_MESSAGE(1), &tr);

	if (ret < 0) {
		perror("Can't send SPI Message");
		return 5;
	}

	return ret;

}







