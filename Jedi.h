#pragma once  
#include <cstring>
#include<iostream>
enum Rank
    {
        YOUNGLING = 1,
        INITIATE = 2,
        PADAWAN = 3,
        KNIGHT_ASPIRANT = 4,
        KNIGHT = 5,
        MASTER = 6,
        BATTLE_MASTER = 7,
        GRAND_MASTER = 8
    };
class Jedi
{
private:
    char *name;
    unsigned int age;
    char *colourOfSword;
    double power;
    public:
    void destroy()
    {
        delete[] name;
        delete[] colourOfSword;
    }
    void copy(const Jedi& other)
    {
        this->age = other.age;
        this->power = other.power;
        this->rank_jedi = other.rank_jedi;

        int length_name = std::strlen(other.name);
        int length_colour = std::strlen(other.colourOfSword);

        this->name = new (std::nothrow) char[length_name + 1];
        if (this->name == nullptr)
        {
            std::cout << "Memory is unavailable \n";
        }

        for (int i = 0; i < length_name + 1; i++)
        {
            this->name[i] = other.name[i];
        }

        this->colourOfSword = new (std::nothrow) char[length_colour + 1];
        if (this->colourOfSword == nullptr)
        {
            std::cout << "Memory is unavailable \n";
        }

        for (int i = 0; i < length_colour + 1; i++)
        {
            this->colourOfSword[i] = other.colourOfSword[i];
        }
    }

  
    Rank rank_jedi;
    Jedi();
    Jedi(const char *, unsigned int , const char *, double , const Rank &); //removed & at unsigend int and double
    Jedi(const Jedi &);
    Jedi& operator= (const Jedi&);
    ~Jedi();
    void rank_up();
    void rank_down();

    //stronger jedi (power) - operator > < ==
    bool operator==(const Jedi &) const;
    bool operator!=(const Jedi &) const;
    bool operator>(const Jedi &) const;
    bool operator<(const Jedi &) const;
    bool operator>=(const Jedi &) const;
    bool operator<=(const Jedi &) const;

    void print_rank() const;
    void enter_rank();
    friend std::ostream &operator<<(std::ostream &, const Jedi &);
    friend std::istream &operator>>(std::istream &, Jedi &);
    bool younger_jedi(const Jedi &) const;
    char* getName();
    unsigned int getAge();
    char* getColour();
    double getPower();
    Rank getRank();
    void power_up(double);
    void power_down(double);
    void print();
};