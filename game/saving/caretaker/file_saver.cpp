#include "file_saver.h"
#include "../../exeptions/file_load_exeption.h"
void File_Saver::Save_In_Files(Caretaker* caretaker)
{
    
    if(caretaker->GetPlayerMemento())
    {
        file.open(player_var,std::ios::out);
        if(file.is_open())
        {
            std::tuple<int,int,bool,int> player_state = caretaker->GetPlayerMemento()->GetState();
            //std::cout<<std::get<0>(player_state)<<' '<<std::get<1>(player_state)<<' '<<std::get<2>(player_state)<<' '<<std::get<3>(player_state);
            int pl_hash = PlayerHash(std::get<0>(player_state),std::get<1>(player_state),std::get<2>(player_state),std::get<3>(player_state));
            file<<pl_hash<<' '<<std::get<0>(player_state)<<' '<<std::get<1>(player_state)<<' '<<std::get<2>(player_state)<<' '<<std::get<3>(player_state)<<std::endl;
            file.close();
        }
    }
    if(caretaker->GetFieldMemento())
    {
        std::tuple<int,int,std::pair<int,int>,std::pair<int,int>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,bool,int*>field = caretaker->GetFieldMemento()->GetState();
        file.open(field_var,std::ios::out);
        if(file.is_open())
        {
            int var_hash = FieldHash(std::get<0>(field),std::get<1>(field),std::get<7>(field),std::get<8>(field));
            file<<var_hash<<' '<<std::get<0>(field)<<' '<<std::get<1>(field)<<' '<<std::get<7>(field)<<' ';
            for(int i =0;i<4;i++)
            {
                file<<std::get<8>(field)[i]<<' ';
            }
            file<<std::endl;
            file.close();
        }
        file.open(field_coords,std::ios::out);
        if(file.is_open())
        {
            int coords_hash = PairHash(std::get<2>(field),std::get<3>(field));
            file<<coords_hash;
            WritePair(&file,std::get<2>(field));
            WritePair(&file,std::get<3>(field));
            file<<std::endl;
            file.close();
        }
        file.open(open_cells,std::ios::out);
        if(file.is_open())
        {
            int op_cells_hash = VectorHash(std::get<4>(field));
            file<<op_cells_hash;
            for(std::vector<std::pair<int,int>>::iterator iter = std::get<4>(field).begin(); iter!=std::get<4>(field).end();++iter)
            {
                std::pair<int,int>* const coord = iter.base();
                WritePair(&file,*coord);
            }
            file<<std::endl;
            file.close();
        }
        file.open(event_cells,std::ios::out);
        if(file.is_open())
        {
            int ev_cells_hash = VectorHash(std::get<5>(field));
            file<<ev_cells_hash;
            for(std::vector<std::pair<int,int>>::iterator iter = std::get<5>(field).begin(); iter!=std::get<5>(field).end();++iter)
            {
                std::pair<int,int>* const coord = iter.base();
                WritePair(&file,*coord);
            }
            file<<std::endl;
            file.close();
        }
        file.open(explore_cells,std::ios::out);
        if(file.is_open())
        {
            int ex_cells_hash = VectorHash(std::get<6>(field));
            file<<ex_cells_hash;
            for(std::vector<std::pair<int,int>>::iterator iter = std::get<6>(field).begin(); iter!=std::get<6>(field).end();++iter)
            {
                std::pair<int,int>* const coord = iter.base();
                WritePair(&file,*coord);
            }
            file<<std::endl;
            file.close();
        }
    }
}
void File_Saver::Load_From_File(Caretaker* caretaker)
{
    std::tuple<int,int,bool,int> player_state;
    std::tuple<int,int,std::pair<int,int>,std::pair<int,int>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>,bool,int*>field;
    file.open(player_var,std::ios::in);
    if(!file.is_open())
    {
        throw File_Load_Exeption(player_var);
    }
    if(file.is_open())
    {
        std::string str;
        getline(file,str);
        if(str == "")
        {
            throw File_Load_Exeption();
        }
        int pl_hash = 0;
        int blind_mode = 0;
        str = ReadNumber(str,&pl_hash);
        if(str == "")
        {
            throw File_Load_Exeption(player_var);
        }
        str = ReadNumber(str,&std::get<0>(player_state));
        if(str == "")
        {
            throw File_Load_Exeption(player_var);
        }
        str = ReadNumber(str,&std::get<1>(player_state));
        if(str == "")
        {
            throw File_Load_Exeption(player_var);
        }
        str = ReadNumber(str,&blind_mode);
        if(str == "")
        {
            throw File_Load_Exeption(player_var);
        }
        str = ReadNumber(str,&std::get<3>(player_state));  
        std::get<2>(player_state) = bool(blind_mode);
        if(pl_hash!=PlayerHash(std::get<0>(player_state),std::get<1>(player_state),std::get<2>(player_state),std::get<3>(player_state)))
        {
            throw File_Load_Exeption(player_var);
        }
        //int pl_hash = std::stoi(str.substr(0,str.find(' ')));
        //str = str.substr(str.find(' ')+1,str.length()-1);
        //std::cout<<"hash "<<pl_hash<<'\n';
        //std::cout<<"player "<<std::get<0>(player_state)<<' ' <<std::get<1>(player_state)<<' '<<std::get<2>(player_state)<<' '<<std::get<3>(player_state)<<'\n';
        //std::cout<<"player "<<PlayerHash(std::get<0>(player_state),std::get<1>(player_state),std::get<2>(player_state),std::get<3>(player_state))<<'\n';
    }
    file.close();
    file.open(field_var,std::ios::in);
    if(!file.is_open())
    {
        throw File_Load_Exeption(field_var);
    }
    if(file.is_open())
    {
        std::string str;
        getline(file,str);
        if(str == "")
        {
            throw File_Load_Exeption();
        }
        int field_hash = 0;
        int is_walls = 0;
        int* event_chance = new int [4];
        str = ReadNumber(str,&field_hash);
        if(str == "")
        {
            throw File_Load_Exeption(field_var);
        }
        str = ReadNumber(str,&std::get<0>(field));
        if(str == "")
        {
            throw File_Load_Exeption(field_var);
        }
        str = ReadNumber(str,&std::get<1>(field));
        if(str == "")
        {
            throw File_Load_Exeption(field_var);
        }
        str = ReadNumber(str,&is_walls);
        for(int i = 0;i<4;i++)
        {
            str = ReadNumber(str,&event_chance[i]);

        }
        std::get<7>(field) = bool(is_walls);
        std::get<8>(field) = event_chance;
        if(field_hash!=FieldHash(std::get<0>(field),std::get<1>(field),std::get<7>(field),std::get<8>(field)))
        {
            throw File_Load_Exeption(field_var);
        }
        /*std::cout<<"hash "<<field_hash<<'\n';
        std::cout<<"field "<<std::get<0>(field)<<' '<<std::get<1>(field)<<' '<<std::get<7>(field)<<' ';
        for(int i =0;i<4;i++)
        {
            std::cout<<std::get<8>(field)[i]<<' ';
        }
        std::cout<<std::endl;*/
        //std::cout<<"field "<<str<<'\n';
    }
    file.close();
    file.open(field_coords,std::ios::in);
    if(!file.is_open())
    {
        throw File_Load_Exeption(field_coords);
    }
    if(file.is_open())
    {
        std::string str;
        getline(file,str);
        if(str == "")
        {
            throw File_Load_Exeption();
        }
        int coords_hash;
        std::pair<int,int> pl;
        std::pair<int,int> win;
        str = ReadNumber(str,&coords_hash);
        if(str == "")
        {
            throw File_Load_Exeption(field_coords);
        }
        str = ReadNumber(str,&pl.first);
        if(str == "")
        {
            throw File_Load_Exeption(field_var);
        }
        str = ReadNumber(str,&pl.second);
        if(str == "")
        {
            throw File_Load_Exeption(field_var);
        }
        str = ReadNumber(str,&win.first);
        if(str == "")
        {
            throw File_Load_Exeption(field_var);
        }
        str = ReadNumber(str,&win.second);
        std::get<2>(field) = pl;
        std::get<3>(field) = win;
        if(coords_hash!=PairHash(std::get<2>(field),std::get<3>(field)))
        {
            throw File_Load_Exeption(field_coords);
        }
        //std::cout<<"hash "<<coords_hash<<'\n';
        //std::cout<<"coords "<<pl.first<<' '<<pl.second<<' '<<win.first<<' '<<win.second<<'\n';
        //std::cout<<"coords "<<str<<'\n';
    }
    file.close();
    file.open(open_cells,std::ios::in);
    if(!file.is_open())
    {
        throw File_Load_Exeption(open_cells);
    }
    if(file.is_open())
    {
        std::string str;
        getline(file,str);
        if(str == "")
        {
            throw File_Load_Exeption();
        }
        int open_cells_hash = 0;
        std::vector<std::pair<int,int>> open;
        str = ReadNumber(str,&open_cells_hash);
        //std::cout<<"hash "<<open_cells_hash<<'\n';
        //std::cout<<str;
        while(str != "")
        {
            //str = str.substr(1,str.length()-1);
            
            int y;
            int x;
            //y= std::stoi(str.substr(0,str.find(' ')));
            //str = str.substr(str.find(' ')+1,str.length()-1);
            if(str == "")
            {
                throw File_Load_Exeption(open_cells);
            }
            str = ReadNumber(str,&y);
            if(str == "")
            {
                throw File_Load_Exeption(open_cells);
            }
            str = ReadNumber(str,&x);
            std::pair<int,int> coord = std::make_pair(y,x);
            open.push_back(coord);
            //std::cout<<coord.first<<' '<<coord.second<<' ';
        }
        
        //std::cout<<'\n';
        //std::cout<<"hash "<<open_cells_hash<<'\n';
        //std::cout<<"open "<<str<<'\n';
        std::get<4>(field) = open;
        if(open_cells_hash!=VectorHash(std::get<4>(field)))
        {
            throw File_Load_Exeption(open_cells);
        }
    }
    file.close();
    file.open(event_cells,std::ios::in);
    if(!file.is_open())
    {
        throw File_Load_Exeption(event_cells);
    }
    if(file.is_open())
    {
        std::string str;
        getline(file,str);
        if(str == "")
        {
            throw File_Load_Exeption();
        }
        int event_cells_hash = 0;
        std::vector<std::pair<int,int>> event;
        str = ReadNumber(str,&event_cells_hash);
        //std::cout<<"hash "<<event_cells_hash<<'\n';
        //std::cout<<str;
        while(str != "")
        {
            //str = str.substr(1,str.length()-1);
            
            int y;
            int x;
            //y= std::stoi(str.substr(0,str.find(' ')));
            //str = str.substr(str.find(' ')+1,str.length()-1);
            if(str == "")
            {
                throw File_Load_Exeption(open_cells);
            }
            str = ReadNumber(str,&y);
            if(str == "")
            {
                throw File_Load_Exeption(open_cells);
            }
            str = ReadNumber(str,&x);
            std::pair<int,int> coord = std::make_pair(y,x);
            event.push_back(coord);
            //std::cout<<coord.first<<' '<<coord.second<<' ';
        }
        //std::cout<<'\n';
        //std::cout<<"hash "<<open_cells_hash<<'\n';
        //std::cout<<"open "<<str<<'\n';
        std::get<5>(field) = event;
        if(event_cells_hash!=VectorHash(std::get<5>(field)))
        {
            throw File_Load_Exeption(event_cells);
        }
    }
    file.close();
    file.open(explore_cells,std::ios::in);
    if(!file.is_open())
    {
        throw File_Load_Exeption(explore_cells);
    }
    if(file.is_open())
    {
        std::string str;
        getline(file,str);
        if(str == "")
        {
            throw File_Load_Exeption();
        }
        int explore_cells_hash = 0;
        std::vector<std::pair<int,int>> explore;
        str = ReadNumber(str,&explore_cells_hash);
        //std::cout<<"hash "<<explore_cells_hash<<'\n';
        //std::cout<<str;
        while(str != "")
        {
            //str = str.substr(1,str.length()-1);
            
            int y;
            int x;
            //y= std::stoi(str.substr(0,str.find(' ')));
            //str = str.substr(str.find(' ')+1,str.length()-1);
            if(str == "")
            {
                throw File_Load_Exeption(open_cells);
            }
            str = ReadNumber(str,&y);
            if(str == "")
            {
                throw File_Load_Exeption(open_cells);
            }
            str = ReadNumber(str,&x);
            std::pair<int,int> coord = std::make_pair(y,x);
            explore.push_back(coord);
            //std::cout<<coord.first<<' '<<coord.second<<' ';
        }
        //std::cout<<'\n';
        //std::cout<<"hash "<<open_cells_hash<<'\n';
        //std::cout<<"open "<<str<<'\n';
        std::get<6>(field) = explore;
        if(explore_cells_hash!=VectorHash(std::get<6>(field)))
        {
            throw File_Load_Exeption(explore_cells);
        }
    }
    file.close();
    
    //caretaker->GetPlayerMemento()->SetState(player_state);
    //caretaker->GetFieldMemento()->SetState(field);
    Player_Memento* player_memento = new Player_Memento();
    Field_Memento* field_memento = new Field_Memento();
    player_memento->SetState(player_state);
    field_memento->SetState(field);
    caretaker->SetPlayerMemnto(player_memento);
    caretaker->SetFieldMemnto(field_memento);
}
int File_Saver::PlayerHash(int var1,int var2, bool var3, int var4)
{
    int q = 101;
    int x =2;
    int hash = (var1* int(pow(x,3))+ var2* int(pow(x,2)) + var3*x + var4)%q;
    return hash;
}
int File_Saver::FieldHash(int height, int width, bool is_walls, int* event_chance)
{
    int q = 101;
    int x =2;
    int tmp = 0;
    int hash;
    for(int i = 0;i<4;i++)
    {
        tmp += event_chance[i]*int(pow(x,3-i));
    }
    hash = (height*int(pow(x,6))+ width*int(pow(x,5))+is_walls*int(pow(x,4))+tmp)%q;
    return hash;
}
int File_Saver::PairHash(std::pair<int,int>pl_coords, std::pair<int,int> w_coords)
{
    int q = 101;
    int x = 2;
    int hash = (pl_coords.first*int(pow(x,3))+pl_coords.second*int(pow(x,2))+w_coords.first*x+w_coords.second)%q;
    return hash;
}
int File_Saver::VectorHash(std::vector<std::pair<int,int>> vector)
{
    int q = 101;
    int x =2;
    int M = int(pow(x,32));
    int count = 0;
    int hash = 0;
    for(std::vector<std::pair<int,int>>::iterator iter = vector.begin();iter!= vector.end();++iter)
    {
        std::pair<int,int>* const coord = iter.base();
        hash += (coord->first*x+coord->second)%q;
    }
    hash = hash%M;
    return hash;
}
void File_Saver::WritePair(std::fstream* file,std::pair<int,int> pair)
{
    if(!file->is_open())
        return;
    *file<<' '<<pair.first<<' '<<pair.second;
}
std::string File_Saver::ReadNumber(std::string str,int* var)
{
    /*if(str.find(' ')==str.npos)
    {
        *var = std::stoi(str.substr(0,str.length()-1));
        str = "";
        return str;
    }*/
    *var= std::stoi(str.substr(0,str.find(' ')));
    str = str.substr(str.find(' ')+1,str.length()-1);
    return str;
}
