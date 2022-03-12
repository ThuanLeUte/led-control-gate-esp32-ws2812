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
#define NUM_LED           (300) // Total LED of on strip

/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
Adafruit_NeoPixel strip[8] = { Adafruit_NeoPixel() };

/* Function definitions ----------------------------------------------- */
void setup()
{
  strip[0].setPin(IO_LED_BUFFER_0);
  strip[1].setPin(IO_LED_BUFFER_1);
  strip[2].setPin(IO_LED_BUFFER_2);
  strip[3].setPin(IO_LED_BUFFER_3);
  strip[4].setPin(IO_LED_BUFFER_4);
  strip[5].setPin(IO_LED_BUFFER_5);
  strip[6].setPin(IO_LED_BUFFER_6);
  strip[7].setPin(IO_LED_BUFFER_7);

  for (uint8_t i = 0; i < 8; i++)
  {
    strip[i].updateLength(NUM_LED);
    strip[i].updateType(NEO_GRB + NEO_KHZ800);
    strip[i].begin();
    strip[i].setBrightness(30);
  }
}

void loop()
{
  uint16_t i;

  for (uint8_t num_strip = 0; num_strip < 8; num_strip++)
  {
    for (i = 0; i < strip[0].numPixels(); i++)
    {
      strip[num_strip].setPixelColor(i, 200, 250, 0, 0);
    }

    strip[num_strip].show();
  }

}

/* Private function definitions --------------------------------------- */
/* End of file -------------------------------------------------------- */
