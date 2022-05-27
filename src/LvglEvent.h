#ifndef LvglEvent_h
#define LvglEvent_h

#include "Event.h"

extern "C" {
#include "lvgl.h"
}


class LvglEvent : public Event {
public:
  LvglEvent(lv_event_code_t event,lv_obj_t * target, lv_obj_t * currentTarget, void * userData, void * param);
  virtual ~LvglEvent() {};
  lv_obj_t *getTarget();
  lv_obj_t *getCurrentTarget();

protected:

  lv_obj_t * target;
  lv_obj_t * currentTarget;
  // TODO: need to investigate in LVGL to check whether these two parameters will be recycled after the callback
  // If yes, need to copy the data
  void * userData;
  void * param;
};
#endif // LvglEvent_h