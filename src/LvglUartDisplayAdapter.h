#ifndef LvglUartDisplayAdapter_h
#define LvglUartDisplayAdapter_h

#include <Arduino.h>
#include "HardwareSerial.h"
#include "LvglDisplayAdapter.h"
#include "LvglDefs.h"

/*!
 * @brief 基于 LVGL 的 UART 显示服务器
 */

class LvglUartDisplayAdapter : public LvglDisplayAdapter {
  public:
    LvglUartDisplayAdapter(int16_t screenWidth, int16_t screenHeight, int8_t bpp, HardwareSerial* uart);
    virtual ~LvglUartDisplayAdapter() override {};
    using LvglDisplayAdapter::getScreenWidth;
    using LvglDisplayAdapter::getScreenHeight;
    using LvglDisplayAdapter::getColorBit;

  protected:
    HardwareSerial* uart;
};

#endif // LvglUartDisplayAdapter_h
