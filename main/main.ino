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
#define STRIP_MAX (7)

/* Private enumerate/structure ---------------------------------------- */
typedef struct
{
  uint8_t index;
  uint8_t pin_out;
  uint16_t num_led;
  uint16_t brightness;
  uint8_t red;
  uint8_t green;
  uint8_t blue;
}
led_strip_info_t;

/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
#define INFO(_i, _io, _n, _bn, _r, _g, _b) [_i] = {.index = _i, .pin_out = _io, .num_led = _n, .brightness = _bn, .red = _r, .green = _g, .blue = _b}
const led_strip_info_t LED_TABLE[] = 
{
   //     +=========================+=========+========+=====+=======+======+
   //     |Index | Pinout           | Num LED | Bright | Red | Green | Blue |
   //     +-------------------------+---------+--------+-----+-------+------+
      INFO(0     , IO_LED_BUFFER_0  , 20      , 100    ,  255,    255,   255)
     ,INFO(1     , IO_LED_BUFFER_1  , 20      , 100    ,  255,    255,   255)
     ,INFO(2     , IO_LED_BUFFER_2  , 20      , 100    ,  255,    255,   255)
     ,INFO(3     , IO_LED_BUFFER_3  , 20      , 70     ,  229,    153,   249)
     ,INFO(4     , IO_LED_BUFFER_4  , 20      , 50     ,  204,    255,   255)
     ,INFO(5     , IO_LED_BUFFER_5  , 20      , 30     ,   28,    110,   210)
     ,INFO(6     , IO_LED_BUFFER_6  , 20      , 10     ,  130,      0,   186)
   //     +======+==================+=========+========+=====+=======+======+
};
#undef INFO

/* Private variables -------------------------------------------------- */
Adafruit_NeoPixel strip[8] = { Adafruit_NeoPixel() };

/* Function definitions ----------------------------------------------- */
void setup()
{
  for (uint8_t i = 0; i < STRIP_MAX; i++)
  {
    strip[i].setPin(LED_TABLE[i].pin_out);
    strip[i].updateLength(LED_TABLE[i].num_led);
    strip[i].updateType(NEO_GRB + NEO_KHZ800);
    strip[i].setBrightness(LED_TABLE[i].brightness);
    strip[i].begin();
  }
}

void loop()
{
  uint16_t i;

  for (uint8_t num_strip = 0; num_strip < STRIP_MAX; num_strip++)
  {
    for (i = 0; i < strip[0].numPixels(); i++)
    {
      strip[num_strip].setPixelColor(i, LED_TABLE[num_strip].red, LED_TABLE[num_strip].green, LED_TABLE[num_strip].blue, 0);
    }

    strip[num_strip].show();
  }
}

/* Private function definitions --------------------------------------- */
/* End of file -------------------------------------------------------- */
