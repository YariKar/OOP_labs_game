//#include "help.h"

#include <iostream>
#include <cstring>
#include <string>
class MyExeption: public std::exception
{
    int smth;
public:
    MyExeption(int val)
    {
        smth = val;
    }
    std::string what()
    {
        //std::string error = std::to_string(smth);
        std::string error = "Error with "+std::to_string(smth);
        return error;
    }
};
int func(int val)
{
    int res;
    if(val*val>100)
    {
        //std::cout<<"from func"<<val<<'\n';
        throw MyExeption(val);
    }
    res = val*val;
    return res;
}
int main()
{
    //Command_Reader<int> cr(10);
    //cr.print();
    /*bool f;
    std::cin>>f;
    std::cout<<f<<std::endl;*/
    //std::string str = "";
    //int i = str.find('='+1);
    //std::cout<<i<<'\n';
    //for(int i =0;i<=196;i++)
    //{
    //int symb = i;
    //int code[2];
    //code[0] = symb/16;
    //code[1] = symb%16;
    //wchar_t code = wchar_t(symb+33);
    //unsigned char code = char(symb+33);
    //int n_symb = code[0]*16+code[1];
    //std::cout<<symb<<' '<<code[0]<<code[1]<<' '<<n_symb<<'\n';
    //}
    int a = 0;
    std::cin>>a;
    try 
    {
        a= func(a);
    }
    catch(MyExeption& e)
    {
        std::cout<<e.what()<<'\n';
    }
    std::cout<<a<<std::endl;
    return 0;
}