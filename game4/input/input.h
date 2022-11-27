#pragma once
class Input
{
    public:
        virtual void PutFieldSize()=0;
        virtual int GetFieldWidth()=0;
        virtual int GetFieldHeight()=0;
        virtual void PutMove()=0;
        virtual char GetDir()=0;
};