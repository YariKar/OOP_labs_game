#include "../incl.h"
#include "mediator.h"
void Mediator::Move(Field* field, char dir)
{
     if(dir== 'w'|| dir=='a' || dir == 's' ||dir =='d')
        {
            switch (dir)
            {
                case 119: //w
                    //std::cout<<"you press w\n";
                    field->MoveUp();
                    break;
                case 97: //a
                    //std::cout<<"you press a\n";
                    field->MoveLeft();
                    break;
                case 115: //s
                    //std::cout<<"you press s\n";
                    field->MoveDown();
                    break;
                case 100: //d
                    //std::cout<<"you press d\n";
                    field->MoveRight();
                    break;
                default:
                    break;
            }
        }
    //std::cout<<Field::player_x<<' '<<Field::player_y<<'\n';
}