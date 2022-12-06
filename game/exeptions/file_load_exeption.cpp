#include "file_load_exeption.h"

File_Load_Exeption::File_Load_Exeption(std::string filename)
{   
    this->filename = filename;
}
File_Load_Exeption::File_Load_Exeption()
{

}
std::string File_Load_Exeption::what()
{
    if(filename =="")
    {
        return "Загрузочные файлы пусты. Загрузка сохранения невозможна";
    }
    else
    {
        std::string message = "В загрузочном файле "+filename+ " были изменены или удалены данные. Загрузка невозможна";
        return message;
    }
}