#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../logging/tracked_object.h"
#include "../logging/observer.h"
#include "input.h"
class Controller: public Tracked_Object, public Input
{
    private:
        int field_width;
        int field_height;
        char direction;
        bool IsSucsessSize();
        bool IsSucsessLog(bool log);
    public:
        Controller(Observer* observer);
        void PutFieldSize();
        int GetFieldWidth();
        int GetFieldHeight();
        void PutMove();
        char GetDir();
};
#endif 