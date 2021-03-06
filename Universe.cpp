#pragma once
#include "Planet.h"
#include "Planet.cpp"
#include "Jedi.h"
#include "Jedi.cpp"
#include "Universe.h"
#include <iostream>
#include <cassert>
#include <cstring>
#include <fstream>


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
    for(int i=0; i < planets.getSize(); i++)
    {
        if(planets[i].find_jedi(name_jedi) == true)
        {
            std::cout<<"Jedi with this name already exists!"<<std::endl;
            return;
        }
    }
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
    std::cout<<"There's no jedi with this name!\n";
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
    std::cout<<"There's no jedi with this name!\n";
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


void Universe::colour(const char* planet_name, Rank _rank)
{
    for(int i=0; i < planets.getSize(); i++)
    {
        if(strcmp(planets[i].getNamePlanet(), planet_name)==0)
        {
            planets[i].most_used_color(_rank);
            return;
        }
    }
    std::cout<<"There's no planet with this name!\n";
}
void Universe::colour_grandMaster(const char* planet_name)
{
    for(int i=0; i < planets.getSize(); i++)
    {
        if(strcmp(planets[i].getNamePlanet(), planet_name)==0)
        {
            planets[i].most_used_colour_grandMaster();
            return;
        }
    }
    std::cout<<"There's no planet with this name!\n";
}

std::ostream &operator<<(std::ostream & out, const Universe & item)
{
    for(int i = 0; i < item.planets.getSize(); i++)
    {
        out<<"-\n";
        out<<item.planets[i];
    }
    return out;
}

void Universe::save(const char* file_name, const char* changed_name) 
{
    std::ofstream output(file_name, std::fstream::trunc);
    if (output.is_open())
    {
        for (int i = 0; i < this->planets.getSize(); i++)
        {
            output << "-\n";
            output << this->planets[i];
        }
        output << "-\n";

        std::cout<<"Successfully saved in "<< changed_name <<std::endl;
        output.close();
    }
    else
    {
        std::cout << "File " << changed_name << " not opened" << std::endl;
    }
}
void Universe::save_as(const char* file_name, const char* changed_name) 
{
    std::ofstream output(file_name, std::fstream::trunc);
    if (output.is_open())
    {
        for (int i = 0; i < this->planets.getSize(); i++)
        {
            output << "-\n";
            output << this->planets[i];
        }
        output << "-\n";

        std::cout<<"Successfully saved in  "<< changed_name <<std::endl;
        output.close();

    }
    else
    {
        std::cout << "File " << changed_name << " not opened" << std::endl;
    }
}


void Universe::help()
{
    std::cout<<"The following commands are supported:"<<std::endl;
    std::cout<<"open <file>	opens <file>"<<std::endl;
    std::cout<<"close			closes currently opened file"<<std::endl;
    std::cout<<"save			saves the currently open file"<<std::endl;
    std::cout<<"saveas <file>	saves the currently open file in <file>"<<std::endl;
    std::cout<<"help			prints this information"<<std::endl;
}
void Universe::exit()
{
    std::cout<<"Exiting program..."<<std::endl;
}

void Universe::open(const char* file_name, bool & is_opened, const char* changed_name)
{
    std::ifstream input(file_name);
    char planet_name[30];
    unsigned int age;
    char colour[20];
    double _power;
    unsigned int number;
    Rank rank;
    Planet planet;
    char row[50];
    if (input.is_open())
    {
        if (input.good())
        {
            std::cout << "Sucessfully opened  " << changed_name << std::endl;
            while (!input.eof())
            {
                input >> row;
                if (input.eof())
                {
                    is_opened = true;
                    break;
                }
                if (row[0] == '-')
                {
                    input >> planet_name;
                    if (input.eof())
                    {
                        is_opened = true;
                        break;
                    }
                    this->add_planet(planet_name);
                    continue;
                }
                input >> age >> colour >> _power >> number;
                switch (number)
                {
                case 1:
                    rank = YOUNGLING;
                    break;
                case 2:
                    rank = INITIATE;
                    break;
                case 3:
                    rank = PADAWAN;
                    break;
                case 4:
                    rank = KNIGHT_ASPIRANT;
                    break;
                case 5:
                    rank = KNIGHT;
                    break;
                case 6:
                    rank = MASTER;
                    break;
                case 7:
                    rank = BATTLE_MASTER;
                    break;
                case 8:
                    rank = GRAND_MASTER;
                    break;
                };

                this->create_jedi(planet_name, row, age, colour, _power, rank);
            }
        }
        else 
        {
            is_opened = false;
            std::cout<<"Error with file"<<std::endl;
        }
    }
    else
    {
        is_opened = true;
        std::ofstream output(file_name, std::fstream::trunc);
        std::cout<<"File:  "<<changed_name<< "  exists"<<std::endl;
        output.close();
    }
    input.close();
}

void Universe::clear()
{
    planets.clear();
}

bool Universe::search_jedi(const char* name)
{
    for (int i=0; i<planets.getSize();i++)
    {
        if(planets[i].find_jedi(name)==true)
        {
            return true;
        }
    }
    return false;
}

bool Universe::search_planet(const char* name) 
{
    for (int i=0; i < planets.getSize();i++)
    {
        if(strcmp(planets[i].getNamePlanet(), name) == 0)
        {
            return true;
        }
    }
    return false;
}

void Universe::print_two_planets(const char *name_planet1, const char *name_planet2) //printing to planets alphabetically ordered
{
    Vector<Jedi> all_citizens;
    bool exists1 = false;
    bool exists2 = false;
    for (int i = 0; i < planets.getSize(); i++)
    {
        if (strcmp(planets[i].getNamePlanet(), name_planet1) == 0)
        {
            exists1 = true;
            for (int j = 0; j < planets[i].getSize_planet(); j++)
            {
                all_citizens.push_back(planets[i].getCitizens(j));
            }
            break;
        }
    }
    if (!exists1)
    {
        std::cout << "There's no planet with this name! -> first planet \n";
        return;
    }

    for (int i = 0; i < planets.getSize(); i++)
    {
        if (strcmp(planets[i].getNamePlanet(), name_planet2) == 0)
        {
            exists2 = true;
            for (int j = 0; j < planets[i].getSize_planet(); j++)
            {
                all_citizens.push_back(planets[i].getCitizens(j));
            }
            break;
        }
    }
    if (!exists2)
    {
        std::cout << "There's no planet with this name -> second planet!\n";
        return;
    }

    for (int i = 0; i < all_citizens.getSize(); i++) // alphabetical order 
    {
        for (int j = i + 1; j < all_citizens.getSize(); j++)
        {
            if ((strcmp(all_citizens[i].getName(), all_citizens[j].getName()) > 0))
            {
                Jedi helper;
                helper = all_citizens[i];
                all_citizens[i] = all_citizens[j];
                all_citizens[j] = helper;
            }
        }
    }
    for (int i = 0; i < all_citizens.getSize(); i++)
    {
        all_citizens[i].print();
    }
}

size_t Universe::getSize_uni() const
{
    return planets.getSize();
}
size_t Universe::getCapacity_uni() const
{
    return planets.getCapacity();
}
