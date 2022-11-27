#ifndef PLAYER_H
#define PLAYER_H
#include "../field/field.h"
#include "../logging/tracked_object.h"

class Player: public Tracked_Object::Tracked_Object
{
    private:
        int energy;
        int max_energy;
        //bool off_wall_mode;
        bool blind_mode;
        int diff_coef;
    public:
        Player(Observer* observer,int coef);
        //~Player();
        int GetEnergy();
        int GetMaxEnergy();
        bool GetBlindMode(); 
        //bool GetOffWallMode();
        void EatEnergy(); //событие
        void OnBlindMode(); //событие
        void OffBlindMode();
        void Waste_Energy();
        //void Notify(int level,std::string mes);
};
#endif