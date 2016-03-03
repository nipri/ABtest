/*
** AB2016.h (formerly ArrowBoardController.h)
**
** Made by Erik Zane
** Login   <ezane@ezane-ubuntu-desktop.solartech.local>
**
** Started on  Tue Nov 10 10:56:13 2009 Erik Zane
** Last update Tue Nov 10 10:56:13 2009 Erik Zane
**
*/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

#ifndef     ARROWBOARDCONTROLLER_H_
# define    ARROWBOARDCONTROLLER_H_

#define DEBUG

#ifdef DEBUG
	#define debug(...)	printf(__VA_ARGS__)
#else
	#define debug(...)
#endif

unsigned char rx, rx2;


typedef struct arrow_frame {
  uint8_t lampByte1;
  uint8_t lampByte2;
  uint8_t lampByte3;
  uint8_t periodCount;
} ArrowFrame;

typedef struct arrow_pattern
{
  uint8_t patNum;
  uint8_t isFor25Lamp;
  uint8_t numFrames;
  ArrowFrame frames[4];
} ArrowPattern;

#endif    
