#pragma once
#include "String.h"
#include "String.cpp"
#include "Vector.h"
#include "Vector.cpp"
#include "Menu.h"
#include <cstring>
#include <stdlib.h>

//converting string to int
void string_to_int(String& arr, unsigned int& number)
{
    for(int i=0; i < arr.getSize(); i++)
    {
        char currentSymbol = arr[i];
        number*=10;
        number+= (currentSymbol - '0');
    }
}

void string_to_rank(String& arr, Rank& rank)
{
    char* str = arr.getArray();
    if(strcmp(str, "YOUNGLING") == 0)
    {
        rank=YOUNGLING;
    }
    else if (strcmp(str, "INITIATE") == 0)
    {
        rank=INITIATE;
    }
    else if (strcmp(str, "PADAWAN") == 0)
    {
        rank=PADAWAN;
    }
    else if (strcmp(str, "KNIGHT_ASPIRANT") == 0)
    {
        rank=KNIGHT_ASPIRANT;
    }
    else if (strcmp(str, "KNIGHT") == 0)
    {
        rank=KNIGHT;
    }
    else if(strcmp(str, "MASTER") == 0)
    {
        rank=MASTER;
    }
    else if(strcmp(str, "BATTLE_MASTER") == 0)
    {
        rank=BATTLE_MASTER;
    }
    else if (strcmp(str, "GRAND_MASTER") == 0)
    {
        rank=GRAND_MASTER;
    }
    else std::cout<<"There's no such rank!"<<std::endl;
    
}
/*void copy(char* source, char* destination)
{
    int i=0;
    for(; source[i]!='\n'; i++)
    {
        destination[i]=source[i];
    }
    destination[i]='\0';
}*/
Menu::Menu()
{
  //try in string()
    String open ("open");
    String close ("close");
    String save ("save");
    String saveas ("saveas");
    String help ("help");
    String add_planet ("add_planet");
    String create_jedi ("create_jedi");
    String removeJedi ("removeJedi");
    String promote_jedi ("promote_jedi");
    String demote_jedi ("demote_jedi");
    String get_strongest_jedi ("get_strongest_jedi");
    String get_youngest_jedi ("get_youngest_jedi");
    String get_most_used_saber_colour ("get_most_used_saber_color");
    String print ("print");
    String plus ("+");
    comands.push_back(open);//0
    comands.push_back(close);//1
    comands.push_back(save);//2
    comands.push_back(saveas);//3
    comands.push_back(help);//4
    comands.push_back(add_planet);//5
    comands.push_back(create_jedi);//6
    comands.push_back(removeJedi);//7
    comands.push_back(promote_jedi);//8
    comands.push_back(demote_jedi);//9
    comands.push_back(get_strongest_jedi);//10
    comands.push_back(get_youngest_jedi);//11
    comands.push_back(get_most_used_saber_colour);//12
    comands.push_back(print);//13
    comands.push_back(plus); //14


}
Menu::~Menu()
{

}

void Menu::split()
{
    
    splitted_comands.clear();
    String currentWord;
    for(int i = 0; i < command.getSize(); i++)
    {
        if(command[i] == ' ')
        {
            
            splitted_comands.push_back(currentWord);
            currentWord.clear();
            continue;
        }
        currentWord.push_back(command[i]);
    }
    
    splitted_comands.push_back(currentWord); 
}

void Menu::start()
{
char opened_file[50]="";
bool is_opened=false;
int choise;
    do
    {
        
        choise = -1;
        std::cout << "Enter: ";
        command.clear();
        std::cin>>command;
        split();
        char* cmnd = splitted_comands[0].getArray();
        for(int i = 0; i < comands.getSize()-1; i++)
        {
            if(strcmp(cmnd,comands[i].getArray()) == 0)
            {
                choise = i;
                break;
            }
        }
        if(strcmp(splitted_comands[0].getArray(),"exit") == 0)
        {
            choise = 15;
        }

        if( (choise == -1) && (strcmp(splitted_comands[1].getArray(),comands[14].getArray()) == 0))
        {
            choise=14;
        }

        switch(choise)
        {
            case 0: 
            {
                strcpy(opened_file, splitted_comands[1].getArray());
                my_universe.open(opened_file, is_opened);
                
                break;
            }
            case 1:
            {
                if(is_opened)
                {
                    my_universe.clear();
                    is_opened=false;
                    std::cout<<"Successfully closed "<<opened_file<<std::endl;
                }
                else std::cout<<"No file is opened"<<std::endl;
                break;
            }
            case 2:
            {
                if(is_opened)
                {
                    my_universe.save(opened_file);
                }
                else std::cout<<"No file is opened"<<std::endl;
                break;
            }
            case 3: 
            {
                if(is_opened)
                {
                    my_universe.save_as(splitted_comands[1].getArray());
                }
                else std::cout<<"No file is opened"<<std::endl;
                break;
            }
            case 4:
            {
                if(is_opened)
                {
                    my_universe.help();
                }
                else std::cout<<"No file is opened"<<std::endl;
                break;
            }
            case 5:
            {
                if(is_opened)
                {
                    my_universe.add_planet(splitted_comands[1].getArray());
                }
                else std::cout<<"No file is opened"<<std::endl;
                break;
            }
            case 6:
            {
                if(is_opened)
                {   
                    char planet_name[30]="";//1
                    char jedi_name[30]="";//2
                    Rank jedi_rank;//3
                    unsigned int jedi_age=0;//4
                    char jedi_colour[30]="";//5
                    double power_jedi=0;//6
                    strcpy(planet_name, splitted_comands[1].getArray());
                    strcpy(jedi_name, splitted_comands[2].getArray());
                    strcpy(jedi_colour, splitted_comands[5].getArray());
                    power_jedi = std::atof(splitted_comands[6].getArray()); // 2.5!!
                    string_to_int(splitted_comands[4], jedi_age);
                    string_to_rank(splitted_comands[3], jedi_rank);
                    my_universe.create_jedi(planet_name, jedi_name, jedi_age, jedi_colour, power_jedi, jedi_rank);
                }
                else std::cout<<"No file is opened"<<std::endl;
                break;
            }
            case 7:
            {
                if(is_opened)
                {
                    char planet_name[30]="";//1
                    char jedi_name[30]="";//2
                    strcpy(planet_name, splitted_comands[1].getArray());
                    strcpy(jedi_name, splitted_comands[2].getArray());
                    my_universe.remove_jedi(planet_name, jedi_name);
                }
                else std::cout<<"No file is opened"<<std::endl;
                break;
            }
            case 8:
            {
                if(is_opened)
                {
                    char jedi_name[30]="";//1
                    double multiplier=0;//2
                    strcpy(jedi_name, splitted_comands[1].getArray());
                    multiplier = std::atof(splitted_comands[2].getArray()); // 2.5!!

                    my_universe.promote(jedi_name, multiplier);
                }
                else std::cout<<"No file is opened"<<std::endl;
                break;
            }
            case 9:
            {
                if(is_opened)
                {
                    char jedi_name[30]="";//1
                    double multiplier=0;//2
                    strcpy(jedi_name, splitted_comands[1].getArray());
                    multiplier = std::atof(splitted_comands[2].getArray()); // 2.5!!

                    my_universe.demote(jedi_name, multiplier);
                }
                else std::cout<<"No file is opened"<<std::endl;
                break;
            }
            case 10:
            {
                if(is_opened)
                {
                    char planet_name[30]="";//1
                    strcpy(planet_name, splitted_comands[1].getArray());
                    my_universe.get_strongest(planet_name);
                }
                else std::cout<<"No file is opened"<<std::endl;
                break;
            }
            case 11:
            {
                if(is_opened)
                {
                    char planet_name[30]="";//1
                    Rank rank;//2
                    strcpy(planet_name, splitted_comands[1].getArray());
                    string_to_rank(splitted_comands[2], rank);
                    my_universe.get_youngest(planet_name, rank);
                }
                else std::cout<<"No file is opened"<<std::endl;
                break;
            }
            case 12:
            {
                if (is_opened)
                {
                    if (splitted_comands.getSize() == 3)
                    {
                        char planet_name[30] = ""; //1
                        Rank rank;                 //2
                        strcpy(planet_name, splitted_comands[1].getArray());
                        string_to_rank(splitted_comands[2], rank);
                        my_universe.colour(planet_name,rank);
                    }
                    else
                    {
                        char planet_name[30] = ""; //1
                        strcpy(planet_name, splitted_comands[1].getArray());
                        my_universe.colour_grandMaster(planet_name);
                    }
                }
                else std::cout<<"No file is opened"<<std::endl;
                break;
            }
            case 13:
            {   //print
                if(is_opened)
                {
                    char name[30] = ""; //1
                    strcpy(name, splitted_comands[1].getArray());
                    if(my_universe.search_jedi(name)==true)
                    {
                        my_universe.print_jedi_fromUniverse(name);
                    }
                    else if(my_universe.search_planet(name)==true)
                    {
                        my_universe.print_pl_fromUniverse(name);
                    }
                    else
                    {
                        std::cout<<"There's no such jedi or planet!"<<std::endl;
                    }
                }
                else std::cout<<"No file is opened"<<std::endl;
                break;
            }
            
            case 14:
            { 
                if(is_opened)
                {
                    char name1[30] = ""; //0
                    strcpy(name1, splitted_comands[0].getArray());
                    char name2[30] = ""; //2
                    strcpy(name2, splitted_comands[2].getArray());
                    my_universe.print_two_planets(name1,name2);
                    
                }
                else 
                {
                    std::cout<<"No file is opened"<<std::endl;
                }
                break;

            }
            case 15:
            {
                break;
            }
            default:
            { 
                if(is_opened)
                {
                   std::cout<<"No such command exists!"<<std::endl;
                }
                else 
                {
                    std::cout<<"No file is opened"<<std::endl;
                }
                break;
            }
        }
    }
    while(strcmp(splitted_comands[0].getArray(), "exit") != 0);
    std::cout<<"Exiting program..."<<std::endl;
}