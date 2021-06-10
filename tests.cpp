#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include "Vector.h"
#include "Vector.cpp"
#include "String.h"
#include "String.cpp"
#include "Jedi.h"
#include "Jedi.cpp"
#include "Planet.h"
#include "Planet.cpp"
#include "Universe.h"
#include "Universe.cpp"
#include "Menu.h"
#include "Menu.cpp"

TEST_CASE("Vector")
{
    Vector<int> v;
    CHECK(v.getSize() == 0);
    CHECK(v.getCapacity() == 8);
    v.push_back(1);
    v.push_back(7);
    v.push_back(4);
    v.push_back(1);
    v.push_back(8);
    CHECK(v.getSize() == 5);
    CHECK(v.getCapacity() == 8);

    v.pop_back();
    v.pop_back();
    CHECK(v.getSize() == 3);
    CHECK(v.getCapacity() == 8);
    v.clear();
    CHECK(v.getSize() == 0);
    CHECK(v.getCapacity() == 8);
    std::cout<<"----------------------------"<<std::endl;

}
TEST_CASE("String")
{
    String arr;
    CHECK(arr.getSize() == 0);
    CHECK(arr.getCapacity() == 21);
    arr.push_back('a');
    arr.push_back('b');
    arr.push_back('d');
    arr.push_back('v');
    arr.push_back('t');
    arr.push_back('a');
    CHECK(arr.getSize() == 6);
    CHECK(arr.getCapacity() == 21);
    arr.pop_back();
    arr.pop_back();
    CHECK(arr.getSize() == 4);
    CHECK(arr.getCapacity() == 21);
    std::cout<<"----------------------------"<<std::endl;
}
TEST_CASE ("Jedi and Rank")
{
    Jedi t1("Pesho", 10, "blue", 5.5, YOUNGLING);
    Jedi t2("Gosho", 7, "red", 4, MASTER);
    t1=t2;
    CHECK(strcmp(t1.getName(), t2.getName()) == 0);
    CHECK(strcmp(t1.getColour(), t2.getColour()) == 0);
    CHECK(t1.getRank() == t2.getRank());
    CHECK(t1.getPower() == t2.getPower());
    CHECK(t1.getAge() == t2.getAge());
    t1.rank_down();
    CHECK(t1.getRank() == KNIGHT);
    t2.rank_up();
    CHECK(t2.getRank() == BATTLE_MASTER);

    Jedi t3("Pesho", 10, "blue", 5.5, INVALID_CASE);
    t3.rank_up();
    CHECK(t3.getRank() == INVALID_CASE);
    std::cout<<"----------------------------"<<std::endl;

}
TEST_CASE ("Planet")
{
    Planet p1;
    CHECK(p1.getNamePlanet() == nullptr);
    CHECK(p1.getCapacity_planet() == 8);
    CHECK(p1.getSize_planet() == 0);
    Planet p2("Saturn");
    CHECK(strcmp (p2.getNamePlanet(),"Saturn") == 0);
    CHECK(p2.getCapacity_planet() == 8);
    CHECK(p2.getSize_planet() == 0);
    p2.create_jedi_planet("Pe", 10, "red", 8, YOUNGLING);//
    p2.create_jedi_planet("Go",9, "yellow", 7.8, GRAND_MASTER);
    p2.create_jedi_planet("Dr",10, "blue", 7.8, MASTER);
    p2.create_jedi_planet("Qiya", 9, "blue", 5, YOUNGLING);//
    p2.create_jedi_planet("Pesho", 19, "yellow", 8, MASTER); 
    p2.create_jedi_planet("P", 9, "red", 8, GRAND_MASTER);
    CHECK(p2.getCapacity_planet() == 8);
    CHECK(p2.getSize_planet() == 6);
    p2.remove_jedi_planet("Qiya");
    p2.remove_jedi_planet("Pe");
    p2.remove_jedi_planet("Qi");
    std::cout<<"----------------------------"<<std::endl;
    p2.print_planet();
    std::cout<<"----------------------------"<<std::endl;
    CHECK(p2.getCapacity_planet() == 8);
    CHECK(p2.getSize_planet() == 4);
    p2.print_jedi("Pe");
    std::cout<<"----------------------------"<<std::endl;
    p2.most_used_colour_grandMaster();
    std::cout<<"----------------------------"<<std::endl;
    p2.get_youngest_jedi(GRAND_MASTER);
    std::cout<<"----------------------------"<<std::endl;
    p2.get_strongest_jedi();
    std::cout<<"----------------------------"<<std::endl;
}
TEST_CASE("Universe")
{
    Universe test;
    test.add_planet("Mars");
    test.add_planet("Jupiter");
    CHECK(test.getSize_uni() == 2);
    CHECK(test.getCapacity_uni() == 8);
    test.create_jedi("Mars","Qiya", 9, "yellow", 7.8, YOUNGLING);
    test.create_jedi("Mars","Go",9, "yellow", 5, GRAND_MASTER);
    test.create_jedi("Mars","Qiay",10, "blue", 7, YOUNGLING);
    test.create_jedi("Mars","Gb",9, "blue", 7.3, GRAND_MASTER);
    test.create_jedi("Mars","Gba",9, "yellow", 8.8, GRAND_MASTER);

    test.create_jedi("Jupiter","P", 9, "blue", 8, YOUNGLING);
    test.create_jedi("Jupiter","Dargan", 9, "red", 5, MASTER);
    test.create_jedi("Jupiter","G",9, "red", 7.8, YOUNGLING);
    test.create_jedi("Jupiter","Dragan",10, "blue", 7.8, YOUNGLING);
    std::cout<<"----------------------------"<<std::endl;
    CHECK(test.search_jedi("Gba") == true);
    CHECK(test.search_planet("Jupiter") == true);
    test.remove_jedi("Mars","Qiay");
    CHECK(test.search_jedi("Qiay") == false);
    CHECK(test.search_planet("Saturn") == false);

}


int main()
{
    doctest::Context().run();    
    return 0;
}