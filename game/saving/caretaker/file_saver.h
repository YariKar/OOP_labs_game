#pragma once
#include "../memento/memento.h"
#include "../memento/field_memento.h"
#include "../memento/player_memento.h"
#include "caretaker.h"
class File_Saver
{
    std::fstream file;
    std::string player_var = "saving/caretaker/saves/player.txt";
    std::string field_var = "saving/caretaker/saves/field_var.txt";
    std::string field_coords = "saving/caretaker/saves/field_coords.txt";
    std::string open_cells = "saving/caretaker/saves/open_cells.txt";
    std::string event_cells = "saving/caretaker/saves/event_cells.txt";
    std::string explore_cells = "saving/caretaker/saves/explore_cells.txt";
    int PlayerHash(int var1,int var2, bool var3, int var4);
    int FieldHash(int var1,int var2, bool var3, int* var4);
    int PairHash(std::pair<int,int> coord1, std::pair<int,int> coord2);
    int VectorHash(std::vector<std::pair<int,int>> vector);
    void WritePair(std::fstream* file,std::pair<int,int> pair);
    std::string ReadNumber(std::string str,int* var);
    //bool CheckHash(); сверка хешей и выкидывание исключения если что-то не так (несовпадение хеша значит либо изменение данных либо их несуществование)
    // можно проверять и в load_from_file а если что-то плохо выходить оттуда без заполнения caretaker и продолжать работу
public:
    void Save_In_Files(Caretaker* caretaker);
    void Load_From_File(Caretaker* caretaker);
};