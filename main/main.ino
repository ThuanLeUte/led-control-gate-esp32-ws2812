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
#define NUM_LED 10 // Tong so Led tren mach

/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
Adafruit_NeoPixel strip_0 = Adafruit_NeoPixel(NUM_LED, IO_LED_BUFFER_0, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_1 = Adafruit_NeoPixel(NUM_LED, IO_LED_BUFFER_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_2 = Adafruit_NeoPixel(NUM_LED, IO_LED_BUFFER_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_3 = Adafruit_NeoPixel(NUM_LED, IO_LED_BUFFER_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_4 = Adafruit_NeoPixel(NUM_LED, IO_LED_BUFFER_4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_5 = Adafruit_NeoPixel(NUM_LED, IO_LED_BUFFER_5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_6 = Adafruit_NeoPixel(NUM_LED, IO_LED_BUFFER_6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_7 = Adafruit_NeoPixel(NUM_LED, IO_LED_BUFFER_7, NEO_GRB + NEO_KHZ800);

/* Private function prototypes ---------------------------------------- */
void rainbow_cycle(uint8_t wait);

/* Function definitions ----------------------------------------------- */
void setup()
{
    strip_0.begin();
    strip_1.begin();
    strip_2.begin();
    strip_3.begin();
    strip_4.begin();
    strip_5.begin();
    strip_6.begin();
    strip_7.begin();

    strip_0.setBrightness(30);
    strip_1.setBrightness(30);
    strip_2.setBrightness(30);
    strip_3.setBrightness(30);
    strip_4.setBrightness(30);
    strip_5.setBrightness(30);
    strip_6.setBrightness(30);
    strip_7.setBrightness(30);

    strip_0.Color(255, 255, 255);
    strip_1.Color(255, 255, 255);
    strip_2.Color(255, 255, 255);
    strip_3.Color(255, 255, 255);
    strip_4.Color(255, 255, 255);
    strip_5.Color(255, 255, 255);
    strip_6.Color(255, 255, 255);
    strip_7.Color(255, 255, 255);

    strip_0.show();
    strip_1.show();
    strip_2.show();
    strip_3.show();
    strip_4.show();
    strip_5.show();
    strip_6.show();
    strip_7.show();
}

void loop()
{
  uint16_t i;

  for (i = 0; i < strip_0.numPixels(); i++)
  {
    strip_0.setPixelColor(i, 200, 250, 0, 0);
    strip_1.setPixelColor(i, 200, 250, 0, 0);
    strip_2.setPixelColor(i, 200, 250, 0, 0);
    strip_3.setPixelColor(i, 200, 250, 0, 0);
    strip_4.setPixelColor(i, 200, 250, 0, 0);
    strip_5.setPixelColor(i, 200, 250, 0, 0);
    strip_6.setPixelColor(i, 200, 250, 0, 0);
    strip_7.setPixelColor(i, 200, 250, 0, 0);
  }

  strip_0.show();
  strip_1.show();
  strip_2.show();
  strip_3.show();
  strip_4.show();
  strip_5.show();
  strip_6.show();
  strip_7.show();
}

/* Private function definitions --------------------------------------- */
/* End of file -------------------------------------------------------- */
