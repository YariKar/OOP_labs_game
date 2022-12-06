#pragma once
#include "memento.h"
#include "../../incl.h"
class Field_Memento: public Memento
{
    private:
        std::tuple<int,int,std::pair<int,int>,std::pair<int,int>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,bool, int*> state;
    public:
        void SetState(std::tuple<int,int,std::pair<int,int>,std::pair<int,int>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,bool, int*>);
        std::tuple<int,int,std::pair<int,int>,std::pair<int,int>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,bool, int*> GetState();
        std::pair<int,int> GetFieldSize();
        //void Restore(Saved_Object* obj);
};