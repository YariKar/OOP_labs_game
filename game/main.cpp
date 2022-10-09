#include "incl.h"
#include "field/field.h"
#include "field/cell.h"
#include "output/view.h"
#include "input/controller.h"
#include "player/player.h"
#include "different/mediator.h"
#include "different/event_mediator.h"
int main()
{
    
    Controller controller = Controller();
    controller.PutFieldSize();
    std::cout<<"Идет генерация карты. Пожалуйста, подождите.\n";
    Field* field= new Field(controller.GetFieldWidth(),controller.GetFieldHeight());
    system("clear");
    View view = View(field->GetFieldWidth(),field->GetFieldHeight());
    Mediator mediator = Mediator();
    Player* player = new Player(field->GetFieldHeight()*field->GetFieldWidth());
    Event_Mediator* event_mediator = new Event_Mediator(field,player);
    /*std::cout<<field->GetWinX()<<' '<<field->GetWinY()<<'\n';
    std::cout<<field->GetPlX()<<' '<<field->GetPlY()<<'\n';*/
    if(field->IsWin())
        std::cout<<"Координаты игрока совпали с координатами выхода\n";
    int blind_counter= 5;
    int off_walls_counter = 5;
    while(controller.GetDir()!= 'z' && player->GetEnergy()>0 && !field->IsWin())
    {
        if(player->GetBlindMode())
        {
            blind_counter--;
            if(blind_counter == 0)
            {
                player->OffBlindMode();
                blind_counter = 5;
            }
        }
        if(!field->GetIsWalls())
        {
            off_walls_counter--;
            if(off_walls_counter == 0)
            {
                field->OnWalls();
                off_walls_counter = 5;
            }
        }
        field->OpenCells(player); 
        view.DrawWindow(field);   
        view.DrawStats(player);
        controller.PutMove();
        mediator.Move(field,controller.GetDir());
        if (field->GetField()[field->GetPlY()][field->GetPlX()]->IsEvent())
        {
            field->GetField()[field->GetPlY()][field->GetPlX()]->GetEvent()->event(event_mediator);
            field->GetField()[field->GetPlY()][field->GetPlX()]->DestroyEvent();
        }
        //std::cout<<'\n';
        system("clear");
        player->Waste_Energy();
        if(player->GetEnergy()==0)
            std::cout<<"Вы проиграли\n";
        if(field->IsWin())
            std::cout<<"Вы выиграли ураааааа!\n";
    }
    //std::cout<<counter<<'\n';
    return 0;
}

