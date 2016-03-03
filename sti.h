/*
 * sti.h
 *
 * Made by Erik Zane
 * Login   <ezane@ezane-ubuntu-desktop.solartech.local>
 *
 * Started on  Thu Nov 12 12:57:01 2009 Erik Zane
 * Last update Thu Nov 12 12:57:01 2009 Erik Zane
 */

#ifndef __STI_H__
# define __STI_H__ 1

/**************************
 *      Global defines    *
 **************************/
/**
 * Note: SetIntensity assumes that this is one less than a power of 2
 * (since it uses logical operations to ensure that the index is in
 * range).
 */
#define MAX_INTENSITY_INDEX 0x0f

#define START_UART_RATE  (uint32_t)   9600
#define MAX_UART_RATE    (uint32_t) 230400
#define START_ROW_RATE   (uint32_t)   9600
#define MAX_ROW_RATE     (uint32_t) 230400
#define V3HD_PATTERN_SIZE  10
#define V6HD_PATTERN_SIZE  96
#define V6LD_PATTERN_SIZE  24
#define DESCRIPTION_BYTE_ADDRESS (void *) 0x0
#define INTENSITY_TABLE_ADDRESS (void *) 0x01
#define SERIAL_NUMBER_ADDRESS (void *) 0x23
#define V3HD      0x03
#define V6HD      0x04
#define V6LD      0x05
#define V4HD      0x06
#define IIB_V4HD  0x07
#define AMBER     0x40
#define RED       0x80
#define GREEN     0xc0



/**************************
 *      Global macros     *
 **************************/

// Frequency of the CPU clock passed by compiler as F_CPU
#define UBRR_CALC(baud)      (uint16_t) (F_CPU/16/((uint32_t)baud) - 1)
#define ROW_BAUD_CALC(baud)  (uint16_t) (F_CPU/24/((uint32_t)baud) - 1)
#define CPLD_FREQ_CALC(baud) (uint16_t) (F_CPU/32/((uint32_t)baud) - 1)

#define set_bit(port, bit)       \
  __asm__ __volatile__ (         \
    "sbi %0, %1"                 \
    :  /* no outputs */          \
    : "I" (_SFR_IO_ADDR(port)),  \
      "I" (bit)                  \
    )

#define clear_bit(port, bit)     \
  __asm__ __volatile__ (         \
    "cbi %0, %1"                 \
    :  /* no outputs */          \
    : "I" (_SFR_IO_ADDR(port)),  \
      "I" (bit)                  \
    )

#define ModuleType(desc) (desc & 0x0f)
#define FALSE  (0x00)
#define TRUE  ~(FALSE)

#endif   /* !STI_H_ */
