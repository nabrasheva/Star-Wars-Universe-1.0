#include <iostream>
#include "Jedi.h"
#include "Jedi.cpp"
#include "Planet.h"
#include "Planet.cpp"
#include "Universe.h"
#include "Universe.cpp"
#include <cstring>
#include "Menu.h"
#include "Menu.cpp"
int main()
{
    Menu menu;
    menu.start();
    /*Universe test;
    test.add_planet("Mars");
    test.add_planet("Jupiter");

    test.create_jedi("Mars","Qiya", 9, "yellow", 7.8, YOUNGLING);
    test.create_jedi("Mars","Go",9, "yellow", 5, GRAND_MASTER);
    test.create_jedi("Mars","Qiay",10, "blue", 7, YOUNGLING);
    test.create_jedi("Mars","Gb",9, "blue", 7.3, GRAND_MASTER);
    test.create_jedi("Mars","Gba",9, "yellow", 8.8, GRAND_MASTER);

    
    test.create_jedi("Jupiter","P", 9, "blue", 8, YOUNGLING);
    test.create_jedi("Jupiter","Dargan", 9, "red", 5, MASTER);
    test.create_jedi("Jupiter","G",9, "red", 7.8, YOUNGLING);
    test.create_jedi("Jupiter","Dragan",10, "blue", 7.8, YOUNGLING);
    //test.open();
    //test.promote("Qiay",2.1);
    test.save("Testing.txt");*/

    //test.print_two_planets("Mars", "Jupiter");
    //test.save("Testing.txt");
    /*const Rank rank1 = YOUNGLING;
    const Rank rank2 = MASTER;
    unsigned int age1 = 10;
    unsigned int age2 = 10;*/

    /*Jedi t1("Pesho", 10, "blue", 5.5, YOUNGLING);
    Jedi t2("Gosho", 7, "red", 4, MASTER);
    t1=t2;
    t1.print();
    std::cout<<std::endl;
    t2.print();*/
    
    /*Universe opened;
    bool is=false;
    opened.open("Testing.txt", is);
    //opened.promote("P", 2.5);
    opened.save("Testing.txt");
    std::cout<<is<<std::endl;*/
    //opened.print_pl_fromUniverse("Jupiter");
    //test.print_pl_fromUniverse("Jupiter");
    //test.save("Testing.txt");
    //test.print_pl_fromUniverse("Jupiter");

    /*Planet test("Testing");
    test.create_jedi_planet("Qiya Abrasheva", 9, "blue", 5, MASTER);
    test.create_jedi_planet("Qiy", 9, "yellow", 8, GRAND_MASTER);//
    test.create_jedi_planet("Qiay",9, "blue", 7.8, YOUNGLING);
    test.create_jedi_planet("Dragan",10, "blue", 7.8, GRAND_MASTER); // */
    /*test.create_jedi_planet("Qi", 9, "yellow", 5, YOUNGLING);
    test.create_jedi_planet("Pe", 10, "red", 8, YOUNGLING);
    test.create_jedi_planet("Go",9, "yellow", 7.8, GRAND_MASTER);
    test.create_jedi_planet("Dr",10, "blue", 7.8, MASTER);
    test.create_jedi_planet("Qiya", 9, "blue", 5, YOUNGLING);
    test.create_jedi_planet("Pesho", 19, "yellow", 8, MASTER); 
    test.create_jedi_planet("P", 19, "red", 8, GRAND_MASTER); */
    //test.remove_jedi_planet("Qiy");
    //test.print_planet();
    //std::cout<<test<<std::endl;
 
    return 0;
}