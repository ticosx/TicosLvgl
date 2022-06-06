#ifndef Lvgl_Input_Adapter_h
#define Lvgl_Input_Adapter_h

#include "InputAdapter.h"
#include "LvglDefs.h"
/*!
 * @brief The class which defines an input device
 */
class LvglInputAdapter : public InputAdapter {
  public:
    LvglInputAdapter(){};
    LvglInputAdapter(TwoWire* i2c, uint8_t addr) : InputAdapter(i2c, addr){};
    LvglInputAdapter(Adafruit_I2CDevice *i2cdevice) : InputAdapter(i2cdevice){};
    virtual ~LvglInputAdapter(){};
    virtual void readLvglInputData(input_data* input) {};

    // 返回一个符合 LVGL 标准的输入回调函数指针
    lvgl_input_drv getInputCb() {return input_cb;}

  protected:
    lvgl_input_drv input_cb;
};
#endif