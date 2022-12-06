#pragma once
#include "memento.h"
#include "../../incl.h"
//#include "../../player/player.h"

class Player_Memento: public Memento
{
    private:
        /*int energy;
        int max_energy;
        bool blind_mode;
        int diff_coef;*/
        std::tuple<int,int,bool,int> state;
    public:
        void SetState(std::tuple<int,int,bool,int> player_state);
        std::tuple<int,int,bool,int> GetState();
        //void Restore(Saved_Object* obj);
};