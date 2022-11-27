#include "../incl.h"
#include "tracked_object.h"
#include "message.h"

void Tracked_Object::Notify(std::string level,std::string message)
{
    this->message = new Message(level,message);
    observer->SetMessage(this->message);
    //this->message->~Message();
    this->message->~Message();
}
Observer* Tracked_Object::GetObserver()
{
    return observer;
}
void Tracked_Object::SetObserver(Observer* observer)
{
    this->observer = observer;
}