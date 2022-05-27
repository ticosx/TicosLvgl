#ifndef LvglObj_H
#define LvglObj_H

extern "C" {
#include "lvgl.h"
}

class LvglObj {
    public:

        LvglObj(LvglObj*);
        virtual ~LvglObj();
        lv_obj_t *getLvglObj(){return obj;}

    protected:
        lv_obj_t *obj;
        LvglObj* parent;
};

#endif