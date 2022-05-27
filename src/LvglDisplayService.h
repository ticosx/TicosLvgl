#ifndef LvglDisplayService_h
#define LvglDisplayService_h

#include <Arduino.h>
#include "Service.h"
#include "LvglDisplayAdapter.h"
#include "LvglInputAdapter.h"
#include "LvglDefs.h"

/*!
 * @brief 基于 LVGL 的显示服务器
 */

class LvglDisplayService : public Service {
  public:
    LvglDisplayService(LvglDisplayAdapter*, LvglInputAdapter*, bool double_buffer = false);
    virtual ~LvglDisplayService() override {};
    void begin();
    void loop();
    void end();
    void registerDispDevice(LvglDisplayAdapter*);
    void registerInputDevice(LvglInputAdapter*);
  private:
    lv_disp_draw_buf_t draw_buf;
    void *buf;
    void *buf1;
    bool double_buffer;
};

#endif // LvglDisplayService_h
