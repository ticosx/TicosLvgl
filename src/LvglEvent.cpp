#include "LvglEvent.h"

/*!
 * @brief LVGL 事件类。由于 Ticos 运行时的机制所限，无法实时支持前台回调，因此需要封装 LVGL 事件
 * 以便通过 EventBus 进入 Ticos 运行时循环机制
 */
LvglEvent::LvglEvent(lv_event_code_t event, lv_obj_t * target, lv_obj_t * currentTarget, void * userData, void * param)
   : Event(EVT_LVGL, event), target(target), currentTarget(currentTarget), userData(userData), param(param){
}
/**
 * @brief 获得事件目标
 *
 * @return: 事件目标
 */
lv_obj_t *LvglEvent::getTarget() {
  return target;
}

/**
 * @brief 获得事件当前目标
 *
 * @return: 事件当前目标
 */
lv_obj_t *LvglEvent::getCurrentTarget() {
  return currentTarget;
}