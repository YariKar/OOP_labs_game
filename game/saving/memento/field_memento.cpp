#include "field_memento.h"
#include "../saved_object.h"

void Field_Memento::SetState(std::tuple<int,int,std::pair<int,int>,std::pair<int,int>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,bool, int*>field_state)
{
    state = field_state;
}
std::tuple<int,int,std::pair<int,int>,std::pair<int,int>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,bool, int*> Field_Memento::GetState()
{
    return state;
}
std::pair<int,int> Field_Memento::GetFieldSize()
{
    //std::cout<<std::get<0>(*state)<<' '<<std::get<1>(*state);
    std::pair<int,int> size = std::make_pair(std::get<0>(state),std::get<1>(state));
    return size;
}