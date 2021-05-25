#pragma once
#include <iostream>
#include "Jedi.h"
#include "Jedi.cpp"
#include "Vector.h"
#include "Vector.cpp"

class Planet
{
    private:
    char *name_planet;
    Vector <Jedi> citizens;

    void copy(const Planet & other)
    {
        int length_name = std::strlen(other.name_planet);
        this->name_planet = new (std::nothrow) char[length_name + 1];
        if (this->name_planet == nullptr)
        {
            std::cout << "Memory is unavailable \n";
        }

        for (int i = 0; i < length_name + 1; i++)
        {
            this->name_planet[i] = other.name_planet[i];
        }
        this->citizens=other.citizens;
 

    }
    void destroy()
    {
        delete[] name_planet;
    }

    public:
    Planet();
    Planet(const char *);
    Planet(const Planet &);
    Planet &operator=(const Planet &);
    ~Planet();
    void promote_jedi(const char*, double);
    void demote_jedi(const char*, double);
    void print_planet();
    void create_jedi_planet(const char *, unsigned int , const char *, double , const Rank);
    void remove_jedi_planet(const char *);
    void print_jedi(const char *);
    void get_youngest_jedi(Rank);
    void get_strongest_jedi();
    void most_used_color(Rank);
    char* getNamePlanet();
    void most_used_colour_grandMaster();
    Jedi getCitizens(unsigned int);
    size_t getSize_planet() const;
    size_t getCapacity_planet() const;
    bool find_jedi(const char*);
    friend std::ostream &operator<<(std::ostream &, const Planet &);


};