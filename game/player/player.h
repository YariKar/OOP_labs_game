#ifndef PLAYER_H
#define PLAYER_H
#include "../field/field.h"
#include "../logging/tracked_object.h"
#include "../saving/saved_object.h"
#include "../saving/memento/memento.h"
#include "../saving/memento/player_memento.h"
class Player: public Tracked_Object::Tracked_Object, public Saved_Object
{
    private:
        int energy;
        int max_energy;
        //bool off_wall_mode;
        bool blind_mode;
        int diff_coef;
    public:
        Player(Observer* observer,int coef);
        Player(Observer* observer);
        //~Player();
        int GetEnergy();
        int GetMaxEnergy();
        bool GetBlindMode(); 
        //bool GetOffWallMode();
        void EatEnergy(); //событие
        void OnBlindMode(); //событие
        void OffBlindMode();
        void Waste_Energy();
        Player_Memento* save();
        void load(Player_Memento* memento);
        //void Notify(int level,std::string mes);
};
#endif