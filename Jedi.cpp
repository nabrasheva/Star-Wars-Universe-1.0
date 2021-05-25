#include <iostream>
#include "Jedi.h"
#include <cstring>

#pragma once
Jedi::Jedi()
{
    age = 0;
    power = 0;
    name = nullptr;
    colourOfSword = nullptr;
    rank_jedi = YOUNGLING;
}

Jedi::Jedi(const char *_name, unsigned int _age, const char *_colour, double _power, const Rank &t)
{
    if (_name != nullptr)
    {
        int length_name = std::strlen(_name);
        //delete[] this->name;
        name = new (std::nothrow) char[length_name + 1];
        if (name == nullptr)
        {
            std::cout << "Could not allocate memory for Jedi name." << std::endl;
        }
        else
        {
            std::strcpy(name, _name);
        }
    }

    if (_colour != nullptr)
    {
        int length_colour = std::strlen(_colour);
        //delete[] this->colourOfSword;
        colourOfSword = new (std::nothrow) char[length_colour + 1];
        if (colourOfSword == nullptr)
        {
            std::cout << "Could not allocate memory for colour of the Sword." << std::endl;
        }
        else
        {
            std::strcpy(colourOfSword, _colour);
        }
    }
    age = _age;
    power = _power;
    rank_jedi = t;
}

Jedi::Jedi(const Jedi &other)
{
    this->copy(other);
}

Jedi &Jedi::operator=(const Jedi & other)
{
    if (this != &other)
    {
        this->destroy();
        this->copy(other);
    }
    return *this;
}

Jedi::~Jedi()
{
    this->destroy();
}

void Jedi::enter_rank()
{
    int number;
    std::cout << "Enter rank of Jedi:" << std::endl;
    std::cout << "YOUNGLING = 1, INITIATE = 2, PADAWAN = 3, KNIGHT_ASPIRANT = 4, " << std::endl;
    std::cout << "KNIGHT = 5, MASTER = 6, BATTLE_MASTER = 7,GRAND_MASTER = 8" << std::endl;
    std::cin >> number;
    switch (number)
    {
    case 1:
        this->rank_jedi = YOUNGLING;
        break;
    case 2:
        this->rank_jedi = INITIATE;
        break;
    case 3:
        this->rank_jedi = PADAWAN;
        break;
    case 4:
        this->rank_jedi = KNIGHT_ASPIRANT;
        break;
    case 5:
        this->rank_jedi = KNIGHT;
        break;
    case 6:
        this->rank_jedi = MASTER;
        break;
    case 7:
        this->rank_jedi = BATTLE_MASTER;
        break;
    case 8:
        this->rank_jedi = GRAND_MASTER;
        break;
    };
}
void Jedi::print_rank() const
{
    switch (this->rank_jedi)
    {
    case 1:
        std::cout << "YOUNGLING" << std::endl;
        break;
    case 2:
        std::cout << "INITIATE" << std::endl;
        break;
    case 3:
        std::cout << "PADAWAN" << std::endl;
        break;
    case 4:
        std::cout << "KNIGHT_ASPIRANT" << std::endl;
        break;
    case 5:
        std::cout << "KNIGHT" << std::endl;
        break;
    case 6:
        std::cout << "MASTER" << std::endl;
        break;
    case 7:
        std::cout << "BATTLE_MASTER" << std::endl;
        break;
    case 8:
        std::cout << "GRAND_MASTER" << std::endl;
        break;
    }
}

void Jedi::rank_up()
{
    switch (this->rank_jedi)
    {
    case 1:
        this->rank_jedi = INITIATE;
        std::cout << "Rank promoted to INITIATE" << std::endl;
        break;
    case 2:
        this->rank_jedi = PADAWAN;
        std::cout << "Rank promoted to PADAWAN" << std::endl;
        break;
    case 3:
        this->rank_jedi = KNIGHT_ASPIRANT;
        std::cout << "Rank promoted to KNIGHT ASPIRANT" << std::endl;
        break;
    case 4:
        this->rank_jedi = KNIGHT;
        std::cout << "Rank promoted to KNIGHT" << std::endl;
        break;
    case 5:
        this->rank_jedi = MASTER;
        std::cout << "Rank promoted to MASTER" << std::endl;
        break;
    case 6:
        this->rank_jedi = BATTLE_MASTER;
        std::cout << "Rank promoted to BATTLE MASTER" << std::endl;
        break;
    case 7:
        this->rank_jedi = GRAND_MASTER;
        std::cout << "Rank promoted to GRAND MASTER" << std::endl;
        break;
    case 8:
        std::cout << "This Jedi is GRAND MASTER. Cannot be promoted" << std::endl;
        break;
    }
}

void Jedi::rank_down()
{
    switch (this->rank_jedi)
    {
    case 1:
        std::cout << "This Jedi is YOUNGLING. Cannot be demoted" << std::endl;
        break;
    case 2:
        this->rank_jedi = YOUNGLING;
        std::cout << "Rank demoted to YOUNGLING" << std::endl;
        break;
    case 3:
        this->rank_jedi = INITIATE;
        std::cout << "Rank demoted to INITIATE" << std::endl;
        break;
    case 4:
        this->rank_jedi = PADAWAN;
        std::cout << "Rank demoted to PADAWAN" << std::endl;
        break;
    case 5:
        this->rank_jedi = KNIGHT_ASPIRANT;
        std::cout << "Rank demoted to KNIGHT ASPIRANT" << std::endl;
        break;
    case 6:
        this->rank_jedi = KNIGHT;
        std::cout << "Rank demoted to KNIGHT" << std::endl;
        break;
    case 7:
        this->rank_jedi = MASTER;
        std::cout << "Rank demoted to MASTER" << std::endl;
        break;
    case 8:
        this->rank_jedi = BATTLE_MASTER;
        std::cout << "Rank demoted to BATTLE MASTER" << std::endl;
        break;
    }
}

bool Jedi::operator==(const Jedi &other) const
{
    return (this->power == other.power);
}
bool Jedi::operator!=(const Jedi &other) const
{
    return (this->power != other.power);
}
bool Jedi::operator>(const Jedi &other) const
{
    return (this->power > other.power);
}
bool Jedi::operator<(const Jedi &other) const
{
    return (this->power < other.power);
}
bool Jedi::operator>=(const Jedi &other) const
{
    return (*this > other || *this == other);
}
bool Jedi::operator<=(const Jedi &other) const
{
    return (*this < other || *this == other);
}

std::ostream &operator<<(std::ostream &out, const Jedi &item)
{
    for (int i = 0; item.name[i] != '\0'; i++)
    {
        out << item.name[i];
    }
    out << std::endl;
    out << item.age << std::endl;
    for (int i = 0; item.colourOfSword[i] != '\0'; i++)
    {
        out << item.colourOfSword[i];
    }
    out << std::endl;
    out << item.power;
    out << std::endl;
    out<<item.rank_jedi;
    out << std::endl;

    return out;
}
std::istream &operator>>(std::istream &in, Jedi &item)
{
    char *newName = new (std::nothrow) char[60];
    std::cin.getline(newName, 59);
    int length_name = 0;
    for (int i = 0; newName[i] != '\0'; i++)
    {
        length_name++;
    }
    
    item.destroy();
    
    item.name = new (std::nothrow) char[length_name + 1];
    if (item.name == nullptr)
    {
        std::cout << "Memory is unavailable \n";
    }
    for (int i = 0; i < length_name + 1; ++i)
    {
        item.name[i] = newName[i];
    }
    delete[] newName;

    in >> item.age;
    std::cin.ignore();
    char *newColour = new (std::nothrow) char[30];
    std::cin.getline(newColour, 29);
    int length_colour = 0;

    for (int i = 0; newColour[i] != '\0'; i++)
    {
        length_colour++;
    }

    item.colourOfSword = new (std::nothrow) char[length_colour + 1];
    
    if (item.colourOfSword == nullptr)
    {
        std::cout << "Memory is unavailable \n";
    }
    for (int i = 0; i < length_colour + 1; ++i)
    {
        item.colourOfSword[i] = newColour[i];
    }
    delete[] newColour;

    in >> item.power;
    item.enter_rank();
    return in;
}

bool Jedi::younger_jedi(const Jedi &other) const
{
    return (this->age < other.age);
}

char *Jedi::getName()
{
    return this->name;
}
unsigned int Jedi::getAge()
{
    return this->age;
}
char *Jedi::getColour()
{
    return this->colourOfSword;
}
double Jedi::getPower()
{
    return this->power;
}

Rank Jedi::getRank()
{
    return this->rank_jedi;
}

void Jedi::power_up(double multiplier)
{
    this->power += (multiplier * this->power);
}
void Jedi::power_down(double multiplier)
{
    this->power -= (multiplier * this->power);
}

void Jedi::print()
{
    for (int i = 0; this->name[i] != '\0'; i++)
    {
        std::cout << this->name[i];
    }
    std::cout << std::endl;
    std::cout << this->age << std::endl;
    for (int i = 0; this->colourOfSword[i] != '\0'; i++)
    {
        std::cout << this->colourOfSword[i];
    }
    std::cout << std::endl;
    std::cout << this->power;
    std::cout << std::endl;
    this->print_rank();
    std::cout << std::endl;
}