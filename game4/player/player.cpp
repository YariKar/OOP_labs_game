#include "../incl.h"
#include "../field/field.h"
#include "../field/cell.h"
#include "player.h"
Player::Player(Observer* observer,int coef)
{
    Tracked_Object::SetObserver(observer); 
    diff_coef = coef;
    energy = 1*diff_coef;
    max_energy =1*diff_coef;
    //off_wall_mode = false;
    blind_mode = false;
}
int Player::GetEnergy()
{
    return energy;
}
int Player::GetMaxEnergy()
{
    return max_energy;
}
bool Player::GetBlindMode()
{
    return blind_mode;
}
void Player::OnBlindMode()
{
    Notify("info","Произошло событие Blind Trap");
    blind_mode = true;
}
void Player::OffBlindMode()
{
    blind_mode = false;
}
void Player::EatEnergy()
{
    Notify("info","Произошло событие Eat Energy");
    int add_energy = int(0.25*max_energy);
    (max_energy-energy > add_energy) ? energy+=add_energy : energy = max_energy;
}
void Player::Waste_Energy()
{
    energy--;
}