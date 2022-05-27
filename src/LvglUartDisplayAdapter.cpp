#include "LvglUartDisplayAdapter.h"

LvglUartDisplayAdapter::LvglUartDisplayAdapter(int16_t screenWidth, int16_t screenHeight, int8_t bpp, HardwareSerial* uart)
  :LvglDisplayAdapter(screenWidth, screenHeight, bpp)
{
  this->uart = uart;
}