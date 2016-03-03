/*
** ArrowPatterns.c
**
** Made by (Erik Zane)
** Login   <ezane@ezane-ubuntu-desktop.solartech.local>
**
** Started on  Tue Nov 10 12:05:48 2009 Erik Zane
** Last update Sun May 12 01:17:25 2002 Speed Blue
*/

/******************************************/
/*   NOTE:  FRAMES ARE IN REVERSE ORDER   */
/******************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

#include "AB2016.h"


ArrowPattern __EE_RightArrowPattern_15 =
  {
  1,    // Pattern 1
  0,    // 15 lamp
  2,    // 2 frames
  { {0x00, 0x00, 0x00, 40},
    {0xfa, 0x15, 0xc0, 24},
    {0x00, 0x00, 0x00, 0},
    {0x00, 0x00, 0x00, 0} }
  };

ArrowPattern __EE_MovRtArrow_15 =
  {
  2,    // Pattern 2
  0,    // 15 lamp
  4,    // 4 frames
  { {0x00, 0x00, 0x00, 32},
    {0xfa, 0x15, 0xe0, 16},
    {0xf0, 0x01, 0x60, 8},
    {0x30, 0x00, 0x20, 8} }
  };

ArrowPattern __EE_RightChevron_25 =
  {
  3,    // Pattern 3
  1,    // 25 lamp
  4,    // 4 frames
  { {0x00, 0x00, 0x00, 32},
    {0x4b, 0x7d, 0xf4, 16},
    {0x41, 0x69, 0x74, 8},
    {0x41, 0x48, 0x20, 8} }
  };

ArrowPattern __EE_DoubleArrow_15 =
  {
  4,    // Pattern 4
  0,    // 15 lamp
  2,    // 2 frames
  { {0x00, 0x00, 0x00, 40},
    {0xdf, 0x1d, 0xa0, 24},
    {0x00, 0x00, 0x00, 0},
    {0x00, 0x00, 0x00, 0} }
  };

ArrowPattern __EE_FourDots_15 =
  {
  5,    // Pattern 5
  0,    // 15 lamp
  2,    // 2 frames
  { {0x00, 0x00, 0x00, 40},
    {0x03, 0x18, 0x40, 24},
    {0x00, 0x00, 0x00, 0},
    {0x00, 0x00, 0x00, 0} }
  };

ArrowPattern __EE_ThreeDiamonds_25 =
  {
  6,    // Pattern 6
  1,    // 25 lamp
  4,    // 4 frames
  { {0x00, 0x00, 0x00, 16},
    {0x40, 0xa1, 0x54, 16},
    {0x00, 0x00, 0x00, 16},
    {0x5f, 0x5d, 0xa8, 16} }
  };

ArrowPattern __EE_HorizLine_15 =
  {
  7,    // Pattern 7
  0,    // 15 lamp
  2,    // 2 frames
  { {0x00, 0x00, 0x00, 40},
    {0xf0, 0x07, 0x40, 24},
    {0x00, 0x00, 0x00, 0},
    {0x00, 0x00, 0x00, 0} }
  };

ArrowPattern __EE_MovDblArrow_15 =
  {
  8,    // Pattern 8
  0,    // 15 lamp
  4,    // 4 frames
  { {0x00, 0x00, 0x00, 32},
    {0xdf, 0x1d, 0xa0, 16},
    {0xc0, 0x01, 0x40, 8},
    {0x80, 0x00, 0x40, 8} }
  };

ArrowPattern __EE_LeftChevron_25 =
  {
  9,    // Pattern 9
  1,    // 25 lamp
  4,    // 4 frames
  { {0x00, 0x00, 0x00, 32},
    {0x57, 0xb9, 0xf8, 16},
    {0x42, 0xb1, 0xd8, 8},
    {0x02, 0x11, 0x88, 8} }
  };

ArrowPattern __EE_MovLtArrow_15 =
  {
  10,   // Pattern 10
  0,    // 15 lamp
  4,    // 4 frames
  { {0x00, 0x00, 0x00, 32},
    {0xd5, 0x0f, 0xe0, 16},
    {0xc0, 0x07, 0xc0, 8},
    {0x00, 0x06, 0x80, 8} }
  };

ArrowPattern __EE_LeftArrowPattern_15 =
  {
  11,   // Pattern 11
  0,    // 15 lamp
  2,    // 2 frames
  { {0x00, 0x00, 0x00, 40},
    {0xd5, 0x0f, 0x60, 24},
    {0x00, 0x00, 0x00, 0},
    {0x00, 0x00, 0x00, 0} }
  };

ArrowPattern __EE_OffPattern =
  {
  12,   // Pattern 12
  0,    // 15 lamp
  2,    // 2 frames
  { {0x00, 0x00, 0x00, 32},
    {0x00, 0x00, 0x00, 32},
    {0x00, 0x00, 0x00, 0},
    {0x00, 0x00, 0x00, 0} }
  };

ArrowPattern __EE_MovRtArrow_25 =
  {
  13,   // Pattern 13
  1,    // 25 lamp
  4,    // 4 frames
  { {0x00, 0x00, 0x00, 32},
    {0xfa, 0x15, 0xe0, 16},
    {0xf0, 0x21, 0x74, 8},
    {0x71, 0x48, 0x20, 8} }
  };

ArrowPattern __EE_MovLtArrow_25 =
  {
  14,   // Pattern 14
  1,    // 25 lamp
  4,    // 4 frames
  { {0x00, 0x00, 0x00, 32},
    {0xd5, 0x0f, 0xe0, 16},
    {0xc0, 0xa7, 0xd0, 8},
    {0x02, 0x17, 0x88, 8} }
  };

ArrowPattern __EE_Initializing_15 =
  {
  15,   // Pattern 15
  0,    // 15 lamp
  4,    // 4 frames
  { {0xf0, 0x07, 0x00, 16},
    {0x70, 0x07, 0x00, 16},
    {0x30, 0x06, 0x00, 16},
    {0x00, 0x00, 0x00, 16} }
  };

ArrowPattern __EE_InitComplete_15 =
  {
  16,   // Pattern 5
  0,    // 15 lamp
  2,    // 2 frames
  { {0x00, 0x00, 0x00, 16},
    {0x03, 0x18, 0x40, 16},
    {0x00, 0x00, 0x00, 0},
    {0x00, 0x00, 0x00, 0} }
  };
