#ifndef LvglDisplayAdapter_h
#define LvglDisplayAdapter_h

#include <Arduino.h>
#include "DisplayAdapter.h"
#include "LvglDefs.h"

/*!
 * @brief 基于 LVGL 的显示适配器
 */

class LvglDisplayAdapter : public DisplayAdapter {
  public:
    LvglDisplayAdapter(int16_t screenWidth, int16_t screenHeight, int8_t bpp, int8_t rotation=1);
    virtual ~LvglDisplayAdapter() override {};
    using DisplayAdapter::getScreenWidth;
    using DisplayAdapter::getScreenHeight;
    using DisplayAdapter::getColorBit;
    using DisplayAdapter::getRotation;

    // 返回一个符合 LVGL 标准的显示回调函数指针
    lvgl_disp_drv getDisplayCb() {return disp_cb;}

  protected:
    lvgl_disp_drv disp_cb;
    
};

#endif // LvglDisplayAdapter_h
