#include "../incl.h"
#include "field.h"
#include "cell.h"
#include "../player/player.h"
Field::Field(Observer* observer,int field_width = 5, int field_height = 5)
{      
    Tracked_Object::SetObserver(observer); 
    //this->observer= observer;  
    event_count = 0;
    event_chance = nullptr;
    Field::field_height = field_height;
    Field::field_width = field_width;
    Field::field = new Cell**[Field::field_height];
    for(int i =0;i<Field::field_height;i++)
    {
        Field::field[i] = new Cell*[Field::field_width];
        for(int j =0;j<Field::field_width;j++)
        {
            
            Field::field[i][j] = new Cell(i,j);
        }
    }
    /*RandPl();
    Notify("info","Создание ирового поля");
    RandField(player_x,player_y);
    Notify("info","Создание клетки победы");
    RandWin();
    Notify("info","Создание событий");
    RandEventCoords();
    Notify("info","Создание игрового поля прошло успешно");*/
}
Field::Field(const Field& obj)
{
    Field::field_height = obj.field_height;
    Field::field_width = obj.field_width;
    Field::player_x = obj.player_x;
    Field::player_y = obj.player_y;
    Field::field = new Cell**[Field::field_height];
    for(int i=0;i<Field::field_height;i++)
    {
        Field::field[i] = new Cell*[Field::field_width];
        for(int j =0;j<Field::field_width;j++)
        {
            Field::field[i][j] = new Cell(*obj.field[i][j]);
        }
    }
}
Field& Field::operator=(const Field& obj)
{
    if(this!=&obj)
    {
        for(int i =0;i<Field::field_height;i++)
        {   
            for(int j =0;j<Field::field_width;j++)
            {
                delete [] Field::field[i][j];
            }
            delete [] Field::field[i];
        }
        delete [] Field::field;
        Field::field_height = obj.field_height;
        Field::field_width = obj.field_width;
        Field::player_x = obj.player_x;
        Field::player_y = obj.player_y;
        Field::field = new Cell**[Field::field_height];
        for(int i =0;i<Field::field_height;i++)
        {
            Field::field[i] = new Cell*[Field::field_width];
            for(int j =0;j<Field::field_width;j++)
            {
                Field::field[i][j] = new Cell(*obj.field[i][j]);
            }
        }
    }
    return *this;
}

Field::Field(Field&& obj)
{
    std::swap(Field::player_x,obj.player_x);
    std::swap(Field::player_y,obj.player_y);
    std::swap(Field::field_height,obj.field_height);
    std::swap(Field::field_width,obj.field_width);
    std::swap(Field::field,obj.field);
}

Field& Field::operator=(Field&& obj)
{
    if(this!=&obj)
    {
        std::swap(Field::player_x,obj.player_x);
        std::swap(Field::player_y,obj.player_y);
        std::swap(Field::field_height,obj.field_height);
        std::swap(Field::field_width,obj.field_width);
        std::swap(Field::field,obj.field);
    }
    return *this;
}

Field::~Field()
{   
    //std::cout<<field_height<<' '<<field_width<<'\n';
    for(int i =0;i<Field::field_height;i++)
    {
        for(int j =0;j<Field::field_width;j++)
        {        
            //std::cout<<"=\n"; 
            field[i][j]->~Cell();
            
        }
        delete [] Field::field[i];
    }
        delete [] Field::field;
    
    /*if(event_chance!=nullptr)
    {
        delete [] event_chance;
        event_chance = nullptr;
    }*/
    //std::cout<<"delete\n";
    //this = NULL;
}
void Field::RandPl()
{
    for (int i = 0;i<field_width;i++)
    {
        for(int j =0;j<field_height;j++)
        {
            if(field[i][j]->GetPossability())
            {
                //std::cout<<"field already\n";
                player_x = 0;
                player_y = 0;
                return;
            }
        }
    }
    srand(time(0));
    player_x = rand()%(field_width-1);
    player_y = rand()%(field_height-1);
    field[player_y][player_x]->SetTruePossability();
    /*bool succsess_rand = false;
    while(succsess_rand!= true)
    {
        srand(time(0));
        Field::player_x = rand()%(Field::field_width-1);
        Field::player_y = rand()%(Field::field_height-1);
        if (Field::field[player_y][player_x]->GetPossability())
            succsess_rand = true;
    }*/
}
void Field:: RandField(int x, int y)
{
    
    //std::cout<<x<<' '<<y<<'\n';
    field[y][x]->CheckPossability();
    /*rec_counter++;
    if(rec_counter>=(field_height*field_width))
    {
        return;
    }*/
    if(rand()%100>=wall_chance)
    {
        field[y][x]->SetTruePossability();
        //std::cout<<y<<' '<<x<<'\n';
    }
    if (!field[y][x]->GetPossability())
    {
        return;
    }

    if (x!=0)
        if (!field[y][x-1]->GetCheckPossability()){
            RandField(x-1,y);
        }
    else
        if (!field[y][field_width-1]->GetCheckPossability()){
            RandField(field_width-1, y);
        }

    if (x!=field_width-1)
        if (!field[y][x+1]->GetCheckPossability()){
            RandField(x+1,y);
        }
    else
        if (!field[y][0]->GetCheckPossability()){
            RandField(0,y);
        }

    if (y!=0)
        if (!field[y-1][x]->GetCheckPossability()){
            RandField(x,y-1);
        }
    else
        if (!field[field_height-1][x]->GetCheckPossability()){
            RandField(x,field_height-1);
        }
    
    if(y!=field_height-1)
        if (!field[y+1][x]->GetCheckPossability()){
            RandField(x,y+1);
        }
    else    
        if (!field[0][x]->GetCheckPossability()){
            RandField(x,0);
        }
}
void Field::RandWin()
{
    bool succsess_rand = false;
    int counter = 0;
    while(succsess_rand!= true)
    {
        counter++;
        if(counter>field_height*field_width)
        {
            break;
        }
        //srand(time(0));
        win_cell_x= rand()%(field_width-1);
        win_cell_y = rand()%(field_height-1);
        if (field[win_cell_y][win_cell_x]->GetPossability()&& player_y!= win_cell_y &&player_x!=win_cell_x)
            succsess_rand = true; 
    }
}
void Field::RandEventCoords()
{
    //std::cout<<event_count<<"\n";
    //int event_numb = event_count;
    /*event_count = int(field_height*field_width/8); //test delete later;
    event_chance = new int(COUNT_EVENT_TYPE);
    event_chance[0] = 25;
    event_chance[1] = 25;
    event_chance[2] = 25;
    event_chance[3] = 25; //test delete later*/
    bool succsess_rand;
    int x;
    int y;
    int counter = 0;
    //std::cout<<event_count<<'\n';
    srand(time(0));
    for(int i = 0;i<event_count;i++)
    {
        
        succsess_rand = false;
        counter = 0;
        while(!succsess_rand)
        {
            counter++;
            if(counter>field_height*field_width)
            {
                //std::cout<<"не ивент\n";
                break;
            }
            x = rand()%(Field::field_width-1);
            y = rand()%(Field::field_height-1);
            if (field[y][x]->GetPossability()&& player_y!= y &&player_x!=x && win_cell_y!= y &&win_cell_x!=x&&!field[y][x]->IsEvent())
                succsess_rand = true;
        }
        //std::cout<<i<<' '<<y<<' '<<x;
        RandEventType(y,x);
    }
}
void Field::RandEventType(int y,int x)
{
    //srand(time(0));
    if(!event_chance)
    {
        event_chance = new int [COUNT_EVENT_TYPE];
        event_chance[0] = 40;
        event_chance[1] = 40;
        event_chance[2] = 10;
        event_chance[3] = 10;
    }
    int event_type = rand()%100;
    //std::cout<<' '<<event_type<<' '<<event_chance[0]<<' '<<event_chance[1]<<' '<<event_chance[2]<<' '<<event_chance[3]<<'\n';
    if(event_type<event_chance[0])
    {
        field[y][x]->SetEvent(0);
    }
    if(event_type>=event_chance[0]&&event_type<event_chance[0]+event_chance[1])
    {
        field[y][x]->SetEvent(1);
    }
    if(event_type>=event_chance[0]+event_chance[1]&&event_type<event_chance[0]+event_chance[1]+event_chance[2])
    {
        field[y][x]->SetEvent(2);
    }
    if(event_type>=event_chance[0]+event_chance[1]+event_chance[2])
    {
        field[y][x]->SetEvent(3);
    }
}

int Field::GetFieldHeight()
{
    return Field::field_height;
}
int Field::GetFieldWidth()
{
    return Field::field_width;
}
Cell*** Field::GetField()
{
    return Field::field;
}
int Field::GetWinX()
{
    return win_cell_x;
}
int Field:: GetWinY()
{
    return win_cell_y;
}
void Field::MoveDown()
{
    if(Field::player_y!=Field::field_height-1)
    {
        if(PossMove(player_x,player_y+1))
            Field::player_y++;
    }
    else
    {
        if (PossMove(player_x,0))
            Field::player_y = 0;
    }
}
void Field::MoveUp()
{
    if(Field::player_y!=0)
    {
        if (PossMove(player_x,player_y-1)) 
            Field::player_y--;
    }
    else
    {
        if (PossMove(player_x,field_height-1))
            Field::player_y = Field::field_height-1;
            
    }
}
void Field::MoveLeft()
{
    if(Field::player_x!=0)
    {
        if(PossMove(player_x-1,player_y))
            Field::player_x--;
    }
    else
    {
        if(PossMove(field_width-1,player_y))
            Field::player_x = Field::field_width-1;
    }
}
void Field::MoveRight()
{
    if(Field::player_x!=Field::field_width-1)
    {
        if(PossMove(player_x+1,player_y))
            Field::player_x++;
    }
    else
    {
        if(PossMove(0,player_y))
            Field::player_x = 0;
    }
}
bool Field::PossMove(int x,int y)
{
    if(!(Field::field[y][x]->GetPossability()))
    {
        //Message* message = new Message(3,"Попытка перехода на непроходимую клетку");
        //Tracked_Object::Notify(message);
        //message->~Message();
        Notify("error","Попытка перехода на непроходимую клетку");
    }
    return (Field::field[y][x]->GetPossability());
}
int Field::GetPlX()
{
    return Field::player_x;
}
int Field::GetPlY()
{
    return Field::player_y;
}
void Field::OpenCells(Player* player)
{
    for(int i = 0;i<field_height;i++)
    {
        for(int j = 0;j<field_width;j++)
        {
            //std::cout<<abs((this->GetPlX()-j)+(this->GetPlY()-i))<<' ';
            if(abs(this->GetPlX()-j)<=1 - player->Player::GetBlindMode() && abs(this->GetPlY()-i)<=1 - player->Player::GetBlindMode())
            {
                field[i][j]->Exploring();
            }
            //std::cout<<field[i][j]->GetExplore()<<' ';
        }
        //std::cout<<'\n';
    }
}
void Field::Recreate_Field() //Teleport event
{
    srand(time(0));
    /*for(int i = 0; i<field_height;i++)
    {
        for(int j = 0; j<field_width;j++)
        {
            field[i][j]->NotExploring();
            if (field[i][j]->IsEvent())
            {
                field[i][j]->DestroyEvent();
            }
        }
    }*/
    player_x = rand()%field_width;
    player_y = rand()%field_height;
    /*RandPl();
    RandField(player_x,player_y);
    RandWin();
    RandEventCoords();*/
    Notify("info","Произошло событие Teleport");
}
void Field::OffWalls()
{
    for(int i =0; i<field_height; i++)
    {
        for(int j =0; j<field_width; j++)
        {
            field[i][j]->WithoutWall();
        }
    }
    is_walls = false;
    //Message* message = new Message(1,"Произошло событие Off Walls");
    //Tracked_Object::Notify(message);
    //message->~Message();
    Notify("info","Произошло событие Off Walls");
}
void Field::OnWalls()
{
    for(int i =0; i<field_height; i++)
    {
        for(int j =0; j<field_width; j++)
        {
            field[i][j]->WithWall();
        }
    }
    is_walls = true;
}
bool Field::IsWin()
{
    return (player_x==win_cell_x && player_y== win_cell_y);
}
bool Field::GetIsWalls()
{
    return is_walls;
}
void Field::SetEventCount(int count)
{
    event_count = count;
}
void Field::SetEventChance(int* chances)
{
    event_chance = chances;
}
void Field::SetWallChance(int chance)
{
    wall_chance = chance;
}
Field_Memento* Field::save()
{
    Field_Memento* memento = new Field_Memento();
    //memento->
    //int field_width = this->field_width;
    //int field_height = this->field_height;
    //bool is_walls = this->is_walls;
    std::pair<int,int> pl_coords = std::make_pair(player_x,player_y);
    std::pair<int,int> win_coords =  std::make_pair(win_cell_x,win_cell_y);
    std::vector<std::pair<int,int>> way;
    std::vector<std::pair<int,int>> events;
    std::vector<std::pair<int,int>> exploring;
    int* event_chance = new int[4];
    for(int i = 0;i<COUNT_EVENT_TYPE;i++)
    {
        event_chance[i] = this->event_chance[i];
    }
    for(int i = 0;i<field_height;i++)
    {
        for(int j = 0;j<field_width;j++)
        {
            if(field[i][j]->GetPossability())
            {
                way.push_back(std::make_pair(j,i));
            }
            if(field[i][j]->IsEvent())
            {
                events.push_back(std::make_pair(j,i));
            }
            if(field[i][j]->GetExplore())
            {
                exploring.push_back(std::make_pair(j,i));
            }
        }
    }
    std::tuple<int,int,std::pair<int,int>,std::pair<int,int>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,bool, int*> state = std::make_tuple(field_height,field_width,pl_coords,win_coords,way,events,exploring,is_walls,event_chance);
    memento->SetState(state);
    return memento;
}
void Field::load(Field_Memento* memento)
{
    srand(time(0));
    std::tuple<int,int,std::pair<int,int>,std::pair<int,int>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,bool, int*> state = memento->GetState();
    field_height = std::get<0>(state);
    field_width = std::get<1>(state);
    std::cout<<field_width<<' '<<field_height<<'\n';
    player_x = std::get<2>(state).first;
    player_y = std::get<2>(state).second;
    win_cell_x = std::get<3>(state).first;
    win_cell_y= std::get<3>(state).second;
    std::vector<std::pair<int,int>> way = std::get<4>(state);
    std::vector<std::pair<int,int>> events = std::get<5>(state);
    std::vector<std::pair<int,int>> exploring = std::get<6>(state);
    is_walls = std::get<7>(state);
    event_chance = std::get<8>(state);
    for(std::vector<std::pair<int,int>>::iterator iter = way.begin(); iter!= way.end(); ++iter)
    {
        std::pair<int,int>* const coord = iter.base();
        field[coord->second][coord->first]->SetTruePossability();
    }
    for(std::vector<std::pair<int,int>>::iterator iter = events.begin(); iter!= events.end(); ++iter)
    {
        std::pair<int,int>* const coord = iter.base();
        RandEventType(coord->second,coord->first);
        //field[coord->second][coord->first]->SetEvent(rand()%4);
    }
    for(std::vector<std::pair<int,int>>::iterator iter = exploring.begin(); iter!= exploring.end(); ++iter)
    {
        std::pair<int,int>* const coord = iter.base();
        field[coord->second][coord->first]->Exploring();
    }
}