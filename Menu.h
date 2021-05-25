#pragma once
#include "String.h"
#include "String.cpp"
#include "Vector.h"
#include "Vector.cpp"
#include "Universe.h"
#include "Universe.cpp"

class Menu
{
    private:
    Vector<String> comands;
    Vector<String> splitted_comands;
    Universe my_universe;
    String command;
    public:
    Menu();
    ~Menu();
    void split();
    void start();
};