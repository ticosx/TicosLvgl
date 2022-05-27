#include "LvglObj.h"

/*!
 * @brief 对 LVGL 中 lv_obj_t 的封装。不过为了简化实现，暂未用到。
 */
LvglObj::LvglObj(LvglObj* parent) : parent(parent) {
  // Create the lvgl object
  obj = lv_obj_create(parent ? parent->getLvglObj() : NULL);
}