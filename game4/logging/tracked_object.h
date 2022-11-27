#ifndef TRACKED_OBJECT_H
#define TRACKED_OBJECT_H
#include "../incl.h"
#include "observer.h"
#include "message.h"
class Tracked_Object
{
    private:
        Observer* observer;
        Message* message;
    public:
        void Notify(std::string level,std::string message);
        Observer* GetObserver();
        void SetObserver(Observer* observer);
};
#endif