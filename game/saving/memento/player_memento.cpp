#include "player_memento.h"
#include "../saved_object.h"
void Player_Memento::SetState(std::tuple<int, int, bool, int> player_state)
{
    state = player_state;
}
std::tuple<int, int, bool, int> Player_Memento::GetState()
{
    return state;
}