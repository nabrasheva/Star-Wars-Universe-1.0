#pragma once
#include <iostream>
#include "Jedi.h"
#include "Jedi.cpp"
#include "Vector.h"
#include "Vector.cpp"
#include "Planet.cpp"
#include "Planet.h"

class Universe
{
    private:
    Vector <Planet> planets; 

    public:
    //Universe();
    //Universe(const Universe &);
    //Universe &operator=(const Universe &);
    ~Universe();
    void add_planet(const char*);//
    void create_jedi(const char*, const char *, unsigned int , const char *, double , const Rank);//
    void remove_jedi(const char*, const char *);//
    void promote(const char*, double);//
    void demote(const char*, double);//
    void get_strongest(const char*);//
    void get_youngest(const char*, Rank);//
    void print_pl_fromUniverse(const char*);//
    void print_jedi_fromUniverse(const char*);//
    void print_two_planets(const char*, const char *);//
    void colour(const char*, Rank);//
    void colour_grandMaster(const char*);//
    friend std::ostream &operator<<(std::ostream &, const Universe &);
    void open(const char*, bool&);
    void save (const char*);
    void save_as(const char*);
    void help();
    void exit();
    void clear();
    bool search_jedi(const char*);
    bool search_planet(const char*);
};