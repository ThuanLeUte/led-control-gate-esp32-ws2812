#include <Adafruit_NeoPixel.h>
#define PIN 23     // Chan DI cua mach
#define NUM_LED 90 // Tong so Led tren mach

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LED, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  strip.begin();
  strip.setBrightness(30);
  strip.show();
}

void loop()
{
  rainbowCycle(10);
}

void rainbowCycle(uint8_t wait)
{
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++)
  { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos)
{
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85)
  {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170)
  {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
