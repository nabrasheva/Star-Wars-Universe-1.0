#pragma once
#include "Planet.h"
#include "Jedi.h"
#include "Jedi.cpp"
#include <iostream>
#include <cassert>
#include <cstring>

Planet::Planet()
{
    name_planet = nullptr;

}
Planet::Planet(const char * _name)
{
 if (_name != nullptr)
    {
        int length_name = std::strlen(_name);
        name_planet = new (std::nothrow) char[length_name + 1];
        if (name_planet == nullptr)
        {
            std::cout << "Could not allocate memory for Planet name." << std::endl;
        }
        else
        {
            strcpy(name_planet, _name);
        }
    }

}
Planet::Planet(const Planet & other)
{
    this->copy(other);
}
Planet &Planet::operator=(const Planet &other)
{
    if(this != &other)
    {
        this->destroy();
        this->copy(other);
    }
    return *this;
}
Planet::~Planet()
{
    this->destroy();

}
void Planet::promote_jedi(const char* jedi_name, double multiplier)
{
    int index = -1;
    int size = this->citizens.getSize();
    bool exists = false;
    while (size)
    { 
        index++;
        if(strcmp(jedi_name, this->citizens[index].getName()) == 0)
        {
            exists = true;
            break;
        }
        size--;
       
    }
    if (!exists)
    {
        std::cout<<"There's no Jedi with this name" << std::endl;
    }
    else
    {
        if (multiplier > 0)
        {
            if (this->citizens[index].getRank() != GRAND_MASTER)
            {
                this->citizens[index].rank_up();
                this->citizens[index].power_up(multiplier);
            }
            else
            {
                std::cout << "Jedi rank is Grand Master" << std::endl;
            }
        }
        else
        {
            std::cout << "Multiplier must be a positive number" << std::endl;
        }
     
    }
}
void Planet::demote_jedi(const char* jedi_name, double multiplier)
{
    int index = -1;
    int size = this->citizens.getSize();
    bool exists=false;
    while (size)
    {
        index++;
        if (strcmp(jedi_name, this->citizens[index].getName()) == 0)
        {
            exists = true;
            break;
        }
        size--;
    }
    if (!exists)
    {
        std::cout << "There's no Jedi with this name" << std::endl;
    }
    else
    {
        if (multiplier > 0)
        {
            if (this->citizens[index].getRank() != YOUNGLING)
            {
                this->citizens[index].rank_down();
                this->citizens[index].power_down(multiplier);
            }
            else
            {
                std::cout << "Jedi rank is Youngling" << std::endl;
            }
        }
        else
        {
            std::cout << "Multiplier must be a positive number" << std::endl;
        }
        
    }
}
void Planet::print_planet() 
{
    std::cout<<"Planet name:";
    for (int i=0; this->name_planet[i] !='\0'; i++)
    {
        std::cout<<this->name_planet[i];
    }

    std::cout<<std::endl;
    for (int i = 0; i < this->citizens.getSize(); i++) //sorting by rank
    {
        int minIndex = i;
        for (int j = i + 1; j < this->citizens.getSize(); j++)
        {
            if (this->citizens[j].getRank() < this->citizens[minIndex].getRank())
                minIndex = j;
        }
        Jedi temp = this->citizens[i];
        this->citizens[i] = this->citizens[minIndex];
        this->citizens[minIndex] = temp;
    }
    //sorting alphabetically 
     for (int i = 0; i < citizens.getSize(); i++)
    {
        for (int j=i+1; j < citizens.getSize(); j++)
        {
            if ((strcmp(citizens[i].getName(), citizens[j].getName()) > 0 )&& 
                    (citizens[i].getRank() == citizens[j].getRank()) )
            {
                Jedi helper;
                helper=citizens[i];
                citizens[i] = citizens[j];
                citizens[j] = helper;
            }
        }
    }

    for (int i = 0; i < this->citizens.getSize(); i++) //printing
    {
        this->citizens[i].print();
    }
}
void Planet::create_jedi_planet(const char *_name, unsigned int _age, const char *_colour, double _power, const Rank _rank)
{
    bool exists = false;
    for (int i = 0; i < this->citizens.getSize(); i++)
    {
        if (strcmp(_name, this->citizens[i].getName())==0)
        {
            exists = true;
            break;
        }
    }
    if (exists)
    {
        std::cout << "Jedi with this name already exists!" << std::endl;
        return;
    }
    else
    {
        Jedi new_jedi(_name, _age, _colour, _power, _rank);
        this->citizens.push_back(new_jedi);
        std::cout << "Jedi added successfully!" << std::endl;
    }

}
void Planet::remove_jedi_planet(const char *_name)
{
    bool exists = false;
    int i = 0;
    for (; i < this->citizens.getSize(); i++)
    {
        if (strcmp(_name, this->citizens[i].getName())==0)
        {
            exists = true;
            break;
        }
    }
    if (exists)
    {
        for (int j=i; j < this->citizens.getSize() - 1; j++)
        {
            this->citizens[j] = this->citizens[j+1];
        }
        this->citizens.pop_back();
        std::cout<<"Removing successful!"<<std::endl;
    }
    else
    {
        std::cout<<"There's no Jedi with this name. Removing failed!"<<std::endl;
    }
}

void Planet::print_jedi(const char *_name)
{
    std::cout<<"Planet name:";
    for (int i=0; this->name_planet[i] !='\0'; i++)
    {
        std::cout<<this->name_planet[i];
    }
    std::cout<<std::endl;
    bool exists = false;
    int i = 0;
    for (; i < this->citizens.getSize(); i++)
    {
        if (strcmp(_name, this->citizens[i].getName())==0)
        {
            exists = true;
            break;
        }
    }
    if (exists)
    {
        this->citizens[i].print();
    }
    else std::cout<<"There's no Jedi with this name!"<<std::endl;
    
}


void Planet::get_youngest_jedi(Rank _rank)
{
    std::cout<<"Planet name:";
    for (int i=0; this->name_planet[i] !='\0'; i++)
    {
        std::cout<<this->name_planet[i];
    }
    std::cout<<std::endl;
    Vector <Jedi> users; 
    for (int i = 0; i < citizens.getSize(); i++)
    {
        if(citizens[i].getRank() == _rank) // get the Jedis with the given rank
        {
            users.push_back(citizens[i]);
        }
    }
    if(users.getSize() == 0)
    {
        std::cout<<"There are no Jedis with this rank!"<<std::endl;
        return;
    }

    int min_age = users[0].getAge();
    for (int i = 0; i < users.getSize(); i++)
    {
        
        if (users[i].getAge() < min_age)  //find the minimum age of these Jedis
                min_age = users[i].getAge() ;
    
    }

    Vector<Jedi> youngests; //find Jedis with minimum age
    for (int i = 0; i < users.getSize(); i++)
    {
        if(users[i].getAge() == min_age)
        youngests.push_back(users[i]);
    }

    //order in alphabetically 
    for (int i = 0; i < youngests.getSize(); i++)
    {
        for (int j=i+1; j<youngests.getSize(); j++)
        {
            if (strcmp(youngests[i].getName(), youngests[j].getName()) > 0)
            {
                Jedi helper;
                helper=youngests[i];
                youngests[i] = youngests[j];
                youngests[j] = helper;
            }
        }
    }

    //print only the first 
   youngests[0].print();
}

void Planet::get_strongest_jedi()
{
    std::cout<<"Planet name:";
    for (int i=0; this->name_planet[i] !='\0'; i++)
    {
        std::cout<<this->name_planet[i];
    }
    std::cout<<std::endl;
    if(this->citizens.getSize() == 0)
    {
        std::cout<<"There are no Jedis on this planet!"<<std::endl;
        return;
    }
    double max_power = this->citizens[0].getPower();
   
    for (int i = 0; i < this->citizens.getSize(); i++)
    {
            if (this->citizens[i].getPower() > max_power) //find the greatest power
                max_power = this->citizens[i].getPower();
    
    } 
    
    for (int i = 0; i < this->citizens.getSize(); i++)
    {
        if(this->citizens[i].getPower() == max_power)
        {
        
            this->citizens[i].print();
            
        }
        
    }
    
}

void Planet::most_used_color(Rank _rank) 
{
    Vector <Jedi> users;
    for (int i = 0; i < this->citizens.getSize(); i++)
    {
        if(this->citizens[i].getRank() == _rank) // get Jedis with given rank
        {
            users.push_back(this->citizens[i]);
        }
    }
    if(users.getSize() == 0)
    {
        std::cout<<"There are no Jedis with this rank!"<<std::endl;
        return;
    }
    Vector <int> colour_counters;
    for (int i = 0; i < users.getSize(); i++) // count the colours within rank
    {
        int counter = 1;
        for (int j = i + 1; j < users.getSize(); j++)
        {
            if(strcmp(users[i].getColour(), users[j].getColour()) == 0) counter++;

        }   
        colour_counters.push_back(counter);
    }
    int max_c = colour_counters[0]; //find the most used
    for (int i = 0; i < colour_counters.getSize(); i++)
    {
        if(colour_counters[i] > max_c) 
                max_c = colour_counters[i];
    }

    for (int i = 0; i < colour_counters.getSize(); i++)
    {
        if(colour_counters[i] == max_c)  // print most used colors
        {
            std::cout<<users[i].getColour()<<std::endl;
        }
    }
 
    std::cout<<std::endl;
}

char* Planet::getNamePlanet() const
{
    return this->name_planet;
}

void Planet::most_used_colour_grandMaster()
{
    Vector <Jedi> users;
    for (int i = 0; i < this->citizens.getSize(); i++)
    {
        if(this->citizens[i].getRank() == GRAND_MASTER) //filter all the Grand Masters
        {
            
            users.push_back(this->citizens[i]);
        }
    }
    if(users.getSize() == 0)
    {
        std::cout<<"There are no Jedis that are Grand Masters!"<<std::endl;
        return;
    }
 
    Vector <int> colour_counters;  //count colors among all citizens
    for (int i = 0; i < users.getSize(); i++)
    {
        int counter = 0;    
        for (int j = 0; j < this->citizens.getSize(); j++)
        {
            if(strcmp(users[i].getColour(), citizens[j].getColour()) == 0) counter++;

        }   
        colour_counters.push_back(counter);
    }

    for (int i = 0; i < users.getSize()-1; i++)
    {
        for (int j = i+1; j < users.getSize(); j++) // if among the users some of them have the same color we leave only the first counter
        {
            if (strcmp(users[i].getColour(), users[j].getColour()) == 0)
            {
                colour_counters[j] = 0;
            }
        }
    }

    int max_c = colour_counters[0]; //find the most used
    for (int i = 0; i < colour_counters.getSize(); i++)
    {
        if(colour_counters[i] > max_c) 
                max_c = colour_counters[i];
    }

    
    for (int i = 0; i < colour_counters.getSize(); i++)
    {
        if(colour_counters[i] == max_c)  // print most used colors
        {
            std::cout<<users[i].getColour()<<std::endl;
            
        }
    }
 
    std::cout<<std::endl;
}

Jedi& Planet::getCitizens(unsigned int index) const
{
    return citizens[index];
}

size_t Planet::getSize_planet() const
{
    return citizens.getSize();
}
size_t Planet::getCapacity_planet() const
{
    return citizens.getCapacity();
}

bool Planet::find_jedi(const char* name)  //find Jedi by name in a Planet
{
    for(int i=0; i<this->citizens.getSize(); i++)
    {
        if(strcmp(this->citizens[i].getName(), name) == 0)
        {
            return true;
        }
    }
    return false;
}

std::ostream &operator<<(std::ostream & out, const Planet & item)
{
    for (int i = 0; item.name_planet[i] != '\0'; i++)
    {
        out << item.name_planet[i];
    }
    out << std::endl;
    for (int i = 0; i < item.citizens.getSize(); i++)
    {
        out<<item.citizens[i];
    }

    return out;
}
