#include <iostream>
#include "Jedi.h"
#include "Jedi.cpp"
#include "Planet.h"
#include "Planet.cpp"
#include "Universe.h"
#include "Universe.cpp"
#include <cstring>
#include <iomanip>  

#include "Menu.h"
#include "Menu.cpp"
int main()
{
    std::cout<<std::setw(45)<<"------------------------------"<<std::endl;
    std::cout<<std::setw(40)<<"Star Wars Universe 0.1"<<std::endl;
    std::cout<<std::setw(45)<<"------------------------------"<<std::endl;
    Menu menu;
    menu.start();
   
   
    return 0;
}