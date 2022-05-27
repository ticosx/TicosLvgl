#ifndef LvglDefs_h
#define LvglDefs_h

extern "C" {
#include "lvgl.h"
}

//LVGL display driver call back
typedef void (*lvgl_disp_drv)( lv_disp_drv_t *, const lv_area_t *, lv_color_t * );

//LVGL input driver call back
typedef void (*lvgl_input_drv)(lv_indev_drv_t *, lv_indev_data_t *);

char *mapFsPath(char *inPath, char *outPath);

#endif // LvglDefs_h