#ifndef CONTROLLER_H
#define CONTROLLER_H
class Controller
{
    private:
        int field_width;
        int field_height;
        char direction;
        bool IsSuccessSize();
    public:
        Controller();
        void PutFieldSize();
        int GetFieldWidth();
        int GetFieldHeight();
        void PutMove();
        char GetDir();
};
#endif 