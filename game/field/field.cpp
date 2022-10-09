#include "../incl.h"
#include "field.h"
#include "cell.h"
#include "../player/player.h"
Field::Field(int field_width = 5, int field_height = 5)
{        
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
    RandPl();
    //srand(time(0));
    std::cout<<"Создание поля\n";
    RandField(player_x,player_y);
    std::cout<<"Создание клетки победы\n";
    RandWin();
    std::cout<<"Создание событий\n";
    RandEventCoords();
    
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
    for(int i =0;i<Field::field_height;i++)
    {
        
        for(int j =0;j<Field::field_width;j++)
        {          
            std::cout<<i<<' '<<j<<'\n';
            //field[i][j]->~Cell();
            delete [] Field::field[i][j];
            
        }
        delete [] Field::field[i];
    }
        delete [] Field::field;
}
void Field::RandPl()
{
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
    if(rand()%100>=30)
    {
        field[y][x]->SetTruePossability();
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
    int event_numb = int(field_height*field_width/8);
    bool succsess_rand;
    int x;
    int y;
    int counter = 0;
    //std::cout<<event_numb<<'\n';
    srand(time(0));
    for(int i = 0;i<event_numb;i++)
    {
        succsess_rand = false;
        counter = 0;
        while(!succsess_rand)
        {
            counter++;
            if(counter>field_height*field_width)
            {
                break;
            }
            x = rand()%(Field::field_width-1);
            y = rand()%(Field::field_height-1);
            if (field[y][x]->GetPossability()&& player_y!= y &&player_x!=x && win_cell_y!= y &&win_cell_x!=x)
                succsess_rand = true;
        }
        field[y][x]->SetEvent(rand()%4);
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
void Field::Recreate_Field() //что
{
    srand(time(0));
    for(int i = 0; i<field_height;i++)
    {
        for(int j = 0; j<field_width;j++)
        {
            field[i][j]->NotExploring();
            if (field[i][j]->IsEvent())
            {
                field[i][j]->DestroyEvent();
            }
        }
    }
    RandPl();
    RandField(player_x,player_y);
    RandWin();
    RandEventCoords();
    
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