/**
 * @file       main.ino
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2022-03-12
 * @author     Thuan Le
 * @brief      Main file
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include <Adafruit_NeoPixel.h>
#include "bsp_io_11.h"

/* Private defines ---------------------------------------------------- */
#define PIN 23     // Chan DI cua mach
#define NUM_LED 10 // Tong so Led tren mach

/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
static Adafruit_NeoPixel strip[8];

/* Private function prototypes ---------------------------------------- */
void rainbow_cycle(uint8_t wait);

/* Function definitions ----------------------------------------------- */
void setup()
{
  strip[0] = Adafruit_NeoPixel(NUM_LED, IO_LED_BUFFER_0, NEO_GRB + NEO_KHZ800);
  strip[1] = Adafruit_NeoPixel(NUM_LED, IO_LED_BUFFER_1, NEO_GRB + NEO_KHZ800);
  strip[2] = Adafruit_NeoPixel(NUM_LED, IO_LED_BUFFER_2, NEO_GRB + NEO_KHZ800);
  strip[3] = Adafruit_NeoPixel(NUM_LED, IO_LED_BUFFER_3, NEO_GRB + NEO_KHZ800);
  strip[4] = Adafruit_NeoPixel(NUM_LED, IO_LED_BUFFER_4, NEO_GRB + NEO_KHZ800);
  strip[5] = Adafruit_NeoPixel(NUM_LED, IO_LED_BUFFER_5, NEO_GRB + NEO_KHZ800);
  strip[6] = Adafruit_NeoPixel(NUM_LED, IO_LED_BUFFER_6, NEO_GRB + NEO_KHZ800);
  strip[7] = Adafruit_NeoPixel(NUM_LED, IO_LED_BUFFER_7, NEO_GRB + NEO_KHZ800);

  for (uint8_t i = 0; i < 8; i++)
  {
    strip[i].begin();
    strip[i].setBrightness(30);
    strip[i].Color(255, 255, 255);
    strip[i].show();
  }
}

void loop()
{
  rainbow_cycle(10);
}

uint32_t Wheel(byte WheelPos)
{
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85)
  {
    return strip[0].Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170)
  {
    WheelPos -= 85;
    return strip[0].Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip[0].Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


void rainbow_cycle(uint8_t wait)
{
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++)
  { 
    for (uint8_t a = 0; a < 8; a++)
    {
      for (i = 0; i < strip[a].numPixels(); i++)
      {
        strip[a].setPixelColor(i, Wheel(((i * 256 / strip[a].numPixels()) + j) & 255));
      }
      strip[a].show();
      delay(wait);
    }
  }
}

/* Private function definitions --------------------------------------- */
/* End of file -------------------------------------------------------- */
