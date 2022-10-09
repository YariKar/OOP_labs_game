#ifndef PLAYER_H
#define PLAYER_H
#include "../field/field.h"
class Player 
{
    private:
        int energy;
        int max_energy;
        //bool off_wall_mode;
        bool blind_mode;
        int diff_coef;
    public:
        Player(int coef);
        int GetEnergy();
        int GetMaxEnergy();
        bool GetBlindMode(); 
        //bool GetOffWallMode();
        void EatEnergy(); //событие
        void OnBlindMode(); //событие
        void OffBlindMode();
        void Waste_Energy();
};
#endif