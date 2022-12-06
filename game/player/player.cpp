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
Player::Player(Observer* observer)
{
    Tracked_Object::SetObserver(observer); 

}
/*Player::~Player()
{
    std::cout<<"delete\n";
}*/
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
Player_Memento* Player::save()
{
    Player_Memento* memento = new Player_Memento();
    //memento->
    std::tuple<int,int,bool,int> state = std::make_tuple(energy,max_energy,blind_mode,diff_coef);
    memento->SetState(state);
    return memento;
}
void Player::load(Player_Memento* memento)
{
    std::tuple<int,int,bool,int> state = memento->GetState();
    
    energy = std::get<0>(state);
    max_energy = std::get<1>(state);
    blind_mode = std::get<2>(state);
    diff_coef = std::get<3>(state);
}