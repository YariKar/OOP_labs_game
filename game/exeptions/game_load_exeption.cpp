#include "game_load_exeption.h"

std::string Game_Load_Exeption::what()
{
    std::string message = "Сохранение отсутствует. Загрузка невозможна.";
    return message;
}