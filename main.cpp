#include <iostream>
#include "Jedi.h"
#include "Jedi.cpp"
#include "Planet.h"
#include "Planet.cpp"
#include "Universe.h"
#include "Universe.cpp"
#include <cstring>
int main()
{
    Universe test;
    test.add_planet("Mars");
    test.add_planet("Jupiter");

    test.create_jedi("Mars","Qiya Abrasheva", 9, "blue", 7.8, YOUNGLING);
    test.create_jedi("Mars","Go",9, "yellow", 5, GRAND_MASTER);
    test.create_jedi("Mars","Qiay",9, "blue", 7.8, YOUNGLING);
    //test.create_jedi("Planet","Qiay",9, "blue", 7.8, YOUNGLING);
    
    test.create_jedi("Jupiter","P", 9, "blue", 8, YOUNGLING);
    test.create_jedi("Jupiter","Dargan", 9, "red", 5, MASTER);
    test.create_jedi("Jupiter","G",10, "red", 7.8, YOUNGLING);
    test.create_jedi("Jupiter","Dragan",10, "blue", 7.8, MASTER);
    test.get_strongest("Mars");

    //test.get_youngest("Jupiter", YOUNGLING);
    //test.promote("Go", -2.5);
    //test.print_jedi_fromUniverse("Go");
    //test.print_two_planets("Mars", "Jupiter");
    //test.print_jedi_fromUniverse("N");
    //test.remove_jedi("Planet_1","P");
    //test.remove_jedi("Planet_2","P");
    //test.print_pl_fromUniverse("Planet_1"); 
    //test.print_pl_fromUniverse("Planet_2");  
    /*Planet test("Testing");
    test.create_jedi_planet("Qiya Abrasheva", 9, "blue", 5, MASTER);
    test.create_jedi_planet("Qiy", 9, "yellow", 8, GRAND_MASTER);//
    test.create_jedi_planet("Qiay",9, "blue", 7.8, YOUNGLING);
    test.create_jedi_planet("Dragan",10, "blue", 7.8, GRAND_MASTER); // 
    test.create_jedi_planet("Qi", 9, "yellow", 5, YOUNGLING);
    test.create_jedi_planet("Pe", 10, "red", 8, YOUNGLING);
    test.create_jedi_planet("Go",9, "yellow", 7.8, GRAND_MASTER);
    test.create_jedi_planet("Dr",10, "blue", 7.8, MASTER);
    test.create_jedi_planet("Qiya", 9, "blue", 5, YOUNGLING);
    test.create_jedi_planet("Pesho", 19, "yellow", 8, MASTER); 
    test.create_jedi_planet("P", 19, "red", 8, GRAND_MASTER); */

    //test.remove_jedi_planet("Qiya Abrasheva");
    //test.remove_jedi_planet("Qiya Abrasheva");
    //test.print_planet();
    //test.most_used_colour_grandMaster();
    //test.most_used_color(YOUNGLING);
    //test.get_youngest_jedi(YOUNGLING);
    //test.get_strongest_jedi();

   
    /*Planet test2("Testing2"); 

    //test2.create_jedi_planet("Gosho",3, "yellow", 7.8, YOUNGLING); 

    test2.create_jedi_planet("Q", 9, "red", 5, YOUNGLING);
    test2.create_jedi_planet("P", 10, "blue", 8, YOUNGLING);
    test2.create_jedi_planet("G",10, "red", 7.8, YOUNGLING);
    test2.create_jedi_planet("D",10, "blue", 7.8, MASTER);*/
    
 
    return 0;
}