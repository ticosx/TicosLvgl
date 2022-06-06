#include "LvglDisplayService.h"
#include "Log.h"

static lv_disp_draw_buf_t draw_buf;

#if LV_USE_LOG != 0
/* Serial debugging */
void print_for_lvgl(const char * buf)
{
    logDebug("%s", buf);
}
#endif

LvglDisplayService::LvglDisplayService(LvglDisplayAdapter* disp, LvglInputAdapter* input, bool double_buffer) : Service(DISPLAY_SERVICE){
  this->double_buffer = double_buffer;
  begin();
  registerDispDevice(disp);
  if(input){
    registerInputDevice(input);
  }
}

void LvglDisplayService::begin(){
  lv_init();
#if LV_USE_LOG != 0
  lv_log_register_print_cb( print_for_lvgl ); /* register print function for debugging */
#endif

}

void LvglDisplayService::loop(){
  lv_timer_handler();
}

void LvglDisplayService::end(){
  lv_deinit();
}

/**
 * @brief 注册显示设备
 *
 * @param disp: 显示设备
 */
void LvglDisplayService::registerDispDevice(LvglDisplayAdapter* disp){
  static lv_disp_drv_t disp_drv;
  if(buf){
    free(buf);
    buf = NULL;
  }
  if(buf1){
    free(buf1);
    buf1 = NULL;
  }
  buf = malloc(sizeof(lv_color_t) * disp->getScreenWidth() * disp->getScreenHeight());
  if(!buf){
    logErr("No memory for lvgl display buffer");
    return;
  }
  if(double_buffer){
    buf1 = malloc(sizeof(lv_color_t) * disp->getScreenWidth() * disp->getScreenHeight());
    if(!buf1){
      logErr("No memory for lvgl display buffer");
      return;
    }
  } else {
     buf1 = NULL;
  }
  lv_disp_draw_buf_init( &draw_buf, buf, buf1, disp->getScreenWidth() * disp->getScreenHeight() );
  lv_disp_drv_init( &disp_drv );
  /*Change the following line to your display resolution*/
  disp_drv.hor_res = disp->getScreenWidth();
  disp_drv.ver_res = disp->getScreenHeight();
  disp_drv.flush_cb = disp->getDisplayCb();
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register( &disp_drv );
}

/**
 * @brief 注册输入设备
 *
 * @param input: 输入设备
 */
void LvglDisplayService::registerInputDevice(LvglInputAdapter* input){
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init( &indev_drv );
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = input->getInputCb();
  lv_indev_drv_register( &indev_drv );
}