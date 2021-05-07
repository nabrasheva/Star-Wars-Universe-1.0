#pragma once
#include "Planet.h"
#include "Planet.cpp"
#include "Jedi.h"
#include "Jedi.cpp"
#include "Universe.h"
#include <iostream>
#include <cassert>
#include <cstring>

Universe::~Universe()
{

}

void Universe::add_planet(const char* name_planet)
{
    bool exists = false;
    for (int i=0; i < planets.getSize(); i++)
    {
        if (strcmp (planets[i].getNamePlanet(), name_planet) == 0)
        {
            exists = true;
            break;
        }
    }
    if (exists)
    {
        std::cout<<"There's a planet with such name!\n";
        return;
    }
    else 
    {
        Planet new_planet(name_planet);
        planets.push_back(new_planet);
        std::cout<<"Planet added successfully!\n";
    }
}
void Universe::create_jedi(const char* name_planet, const char *name_jedi, unsigned int age_jedi, const char * colour_jedi, double power_jedi, const Rank rank_jedi)
{
    for (int i=0; i < planets.getSize(); i++)
    {
        if (strcmp (planets[i].getNamePlanet(), name_planet) == 0)
        {
            planets[i].create_jedi_planet(name_jedi, age_jedi, colour_jedi, power_jedi, rank_jedi);
            return;
        }
    }
    std::cout<<"There's no planet with this name!\n";
}
void Universe::remove_jedi(const char* name_planet, const char * name_jedi)
{
    for (int i=0; i < planets.getSize(); i++)
    {
        if (strcmp (planets[i].getNamePlanet(), name_planet) == 0)
        {
            planets[i].remove_jedi_planet(name_jedi);
            return;
        }
    }
    std::cout<<"There's no planet with this name!\n";
}
void Universe::promote(const char* jedi_name, double multiplier)
{ 
    for(int i=0; i < planets.getSize(); i++)
    {
        if(planets[i].find_jedi(jedi_name) == true)
        {   
            planets[i].promote_jedi(jedi_name, multiplier);
            return;
        }
    }
    std::cout<<"There's no planet with this name!\n";
}
void Universe::demote(const char* jedi_name, double multiplier)
{
    for(int i=0; i < planets.getSize(); i++)
    {
        if(planets[i].find_jedi(jedi_name) == true)
        {   
            planets[i].demote_jedi(jedi_name, multiplier);
            return;
        }
    }
    std::cout<<"There's no planet with this name!\n";
}
void Universe::get_strongest(const char* planet_name)
{
    for (int i=0; i < planets.getSize(); i++)
    {
        if (strcmp (planets[i].getNamePlanet(), planet_name) == 0)
        {
            planets[i].get_strongest_jedi();
            return;
        }
    }
    std::cout<<"There's no planet with this name!\n";
}
void Universe::get_youngest(const char* planet_name, Rank rank)
{
    for (int i=0; i < planets.getSize(); i++)
    {
        if (strcmp (planets[i].getNamePlanet(), planet_name) == 0)
        {
            planets[i].get_youngest_jedi(rank);
            return;
        }
    }
    std::cout<<"There's no planet with this name!\n";
}
void Universe::print_pl_fromUniverse(const char* planet_name)
{
    for (int i=0; i < planets.getSize(); i++)
    {
        if (strcmp (planets[i].getNamePlanet(), planet_name) == 0)
        {
            planets[i].print_planet();
            return;
        }
    }
    std::cout<<"There's no planet with this name!\n";
}
void Universe::print_jedi_fromUniverse(const char* jedi_name)
{   
    for(int i=0; i < planets.getSize(); i++)
    {
        if(planets[i].find_jedi(jedi_name) == true)
        {
            planets[i].print_jedi(jedi_name);
            return;
        }
    }
    std::cout<<"There's no Jedi with this name!"<<std::endl;
}
void Universe::print_two_planets(const char* name_planet1, const char * name_planet2)
{
    Planet planet1;
    Planet planet2;
    bool exists1 = false;
    bool exists2 = false;
    for (int i=0; i < planets.getSize(); i++)
    {
        if (strcmp (planets[i].getNamePlanet(), name_planet1) == 0)
        {
            exists1 = true;
            planet1 = planets[i];
            break;
        }
    }
    if(!exists1)
    {
        std::cout<<"There's no planet with this name! -> first planet \n";
        return;
    }

    for (int i=0; i < planets.getSize(); i++)
    {
        if (strcmp (planets[i].getNamePlanet(), name_planet2) == 0)
        {
            exists2 = true;
            planet2 = planets[i];
            break;
        }
    }
    if(!exists2)
    {
        std::cout<<"There's no planet with this name -> second planet!\n";
        return;
    }
    if(strcmp(planet1.getNamePlanet(), planet2.getNamePlanet()) > 0)
    {
        planet2.print_planet();
        planet1.print_planet();
    }
    else
    {
        planet1.print_planet();
        planet2.print_planet();
    }
}
