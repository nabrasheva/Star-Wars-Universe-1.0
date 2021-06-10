#pragma once
#include "String.h"
#include "String.cpp"
#include "Vector.h"
#include "Vector.cpp"
#include "Menu.h"
#include <cstring>
#include <stdlib.h>
//changing the path of the file 
void change (char * arr)
{
    for (int i=0; arr[i]!='\0'; i++)
    {
        if(arr[i] == '\\')
        {
            arr[i] = '/';
        }
    }
}
// taking the name of the file without the path
void take (char * source, char* destination)
{
    int y = 0;
    for (int i=0; source[i]!='\0'; i++)
    {
        if (source[i] == '/')
        {
            y=i;
        }
    }
    if(y==0)
    {
        strcpy(destination, source);
    }
    else 
    {
    int k=0;
    for (int j = y+1; source[j]!='\0'; j++, k++)
    {
        destination[k]=source[j];
    }
    destination[k]='\0';  
    }

}
//converting string to int
void string_to_int(String &arr, unsigned int &number)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        char currentSymbol = arr[i];
        number *= 10;
        number += (currentSymbol - '0');
    }
}

// converting string to the Rank
void string_to_rank(String &arr, Rank &rank)
{
    char *str = arr.getArray();
    if (strcmp(str, "YOUNGLING") == 0)
    {
        rank = YOUNGLING;
    }
    else if (strcmp(str, "INITIATE") == 0)
    {
        rank = INITIATE;
    }
    else if (strcmp(str, "PADAWAN") == 0)
    {
        rank = PADAWAN;
    }
    else if (strcmp(str, "KNIGHT_ASPIRANT") == 0)
    {
        rank = KNIGHT_ASPIRANT;
    }
    else if (strcmp(str, "KNIGHT") == 0)
    {
        rank = KNIGHT;
    }
    else if (strcmp(str, "MASTER") == 0)
    {
        rank = MASTER;
    }
    else if (strcmp(str, "BATTLE_MASTER") == 0)
    {
        rank = BATTLE_MASTER;
    }
    else if (strcmp(str, "GRAND_MASTER") == 0)
    {
        rank = GRAND_MASTER;
    }
    else
    {
        rank=INVALID_CASE;
        std::cout << "There's no such rank!" << std::endl;
    }
       
}
 //validations for the commands entered by the user
bool check_names(char* arr)
{
    if((arr[0] < 'A') || (arr[0] > 'Z'))
    {
        std::cout<<"Names of planet/jedi should start with a capital letter!"<<std::endl;
        return false;
    }
    for(int i=1; arr[i]!='\0'; i++)
    {
        if((arr[i] < 'a') || (arr[i] > 'z'))
        {
            std::cout<<"Only the first letter of planet/jedi name should be capital!"<<std::endl;
            std::cout<<"Names should be only in letters!"<<std::endl;
            return false;
        }
    }
    return true;
}
bool check_colour(char* arr)
{
    for(int i=0; arr[i]!='\0'; i++)
    {
        if((arr[i] < 'a') || (arr[i] > 'z'))
        {
            std::cout<<"Colour of sword should only have small letters!"<<std::endl;
            return false;
        }
    }
    return true;
}
bool check_age(char *arr)
{
    if (arr[0] == '-')
    {
        std::cout << "Age should be a positive number" << std::endl;
        return false;
    }
    for (int i = 0; arr[i] != '\0'; i++)
    {

        if ((arr[i] < '0') || (arr[i] > '9'))
        {
            std::cout << "Incorrect input for age" << std::endl;
            return false;
        }
    }
    return true;
}
// we used it also for the multiplier used in promote_jedi/ demote_jedi
bool check_power(char *arr)
{
    if ((arr[0] == '-'))
    {
        std::cout << "Power/multiplier should be a positive number" << std::endl;
        return false;
    }
    int count1 = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {

        if (arr[i] == '.')
        {
            count1++;
        }
        if (((arr[i] < '0') || (arr[i] > '9')) && (arr[i] != '.'))
        {
            std::cout << "Incorrect input for power/multiplier" << std::endl;
            return false;
        }
    }

    if (count1 > 1)
    {
        std::cout << "Too many . -> Incorrect input for power/multiplier" << std::endl;
        return false;
    }
    return true;
}
bool check_rank(char* arr)
{
    int count=0;
    for(int i=0; arr[i]!='\0'; i++)
    {
        if(arr[i] == '_')
        {
            count++;
        }
        if(((arr[i] < 'A') || (arr[i] > 'Z')) && (arr[i]!='_') )
        {
            std::cout<<"Rank should be only in capital letters and _"<<std::endl;
            return false;
        }
    }
    if(count>1)
    {
        std::cout<<"Too many _ -> Incorrect input for rank"<<std::endl;
        return false;
    }
    return true;
}
Menu::Menu()
{
    String open("open");
    String close("close");
    String save("save");
    String saveas("saveas");
    String help("help");
    String add_planet("add_planet");
    String create_jedi("create_jedi");
    String removeJedi("removeJedi");
    String promote_jedi("promote_jedi");
    String demote_jedi("demote_jedi");
    String get_strongest_jedi("get_strongest_jedi");
    String get_youngest_jedi("get_youngest_jedi");
    String get_most_used_saber_colour("get_most_used_saber_color");
    String print("print");
    String plus("+");
    comands.push_back(open);                       //0
    comands.push_back(close);                      //1
    comands.push_back(save);                       //2
    comands.push_back(saveas);                     //3
    comands.push_back(help);                       //4
    comands.push_back(add_planet);                 //5
    comands.push_back(create_jedi);                //6
    comands.push_back(removeJedi);                 //7
    comands.push_back(promote_jedi);               //8
    comands.push_back(demote_jedi);                //9
    comands.push_back(get_strongest_jedi);         //10
    comands.push_back(get_youngest_jedi);          //11
    comands.push_back(get_most_used_saber_colour); //12
    comands.push_back(print);                      //13
    comands.push_back(plus);                       //14
}
Menu::~Menu()
{
}

void Menu::split()
{

    splitted_comands.clear();
    String currentWord;
    for (int i = 0; i < command.getSize(); i++)
    {
        if (command[i] == ' ')
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
    char opened_file[50] = "";
    bool is_opened = false;
    int choise;
    do
    {

        choise = -1;
        std::cout << "Enter: ";
        command.clear();
        std::cin >> command;
        split();
        char *cmnd = splitted_comands[0].getArray();
        for (int i = 0; i < comands.getSize() - 1; i++)
        {
            if (strcmp(cmnd, comands[i].getArray()) == 0)
            {
                choise = i;
                break;
            }
        }
        if (strcmp(splitted_comands[0].getArray(), "exit") == 0)
        {
            choise = 15;
        }

        if ((choise == -1) && (splitted_comands.getSize() >= 2) && (strcmp(splitted_comands[1].getArray(), comands[14].getArray()) == 0))
        {
            choise = 14;
        }

        switch (choise)
        {
        case 0:
        {
            if (splitted_comands.getSize() == 2)
            {
                char file_name[40]=""; //used to contain only the file name without the path
                strcpy(opened_file, splitted_comands[1].getArray());
                change(opened_file);
                take(opened_file, file_name);
                my_universe.open(opened_file, is_opened, file_name);
            }
            else
                std::cout << "Incorrect number of arguments!" << std::endl;
            break;
        }
        case 1:
        {
            if (splitted_comands.getSize() == 1)
            {
                if (is_opened)
                {
                    my_universe.clear();
                    is_opened = false;
                    char file_name[40]="";
                    take(opened_file, file_name);
                    std::cout << "Successfully closed " << file_name << std::endl;
                }
                else
                    std::cout << "No file is opened" << std::endl;
            }
            else
                std::cout << "Incorrect number of arguments!" << std::endl;

            break;
        }
        case 2:
        {
            if (splitted_comands.getSize() == 1)
            {
                if (is_opened)
                {
                    char file_name[40]="";
                    take(opened_file, file_name);
                    my_universe.save(opened_file, file_name);
                }
                else
                    std::cout << "No file is opened" << std::endl;
            }
            else
                std::cout << "Incorrect number of arguments!" << std::endl;

            break;
        }
        case 3:
        {
            if (splitted_comands.getSize() == 2)
            {
                if (is_opened)
                {
                    char file_name[40]="";
                    char saving_file[40]="";
                    strcpy(saving_file, splitted_comands[1].getArray());
                    change(saving_file);
                    take(saving_file, file_name);
                    my_universe.save_as(saving_file, file_name);
                }
                else
                    std::cout << "No file is opened" << std::endl;
            }
            else
                std::cout << "Incorrect number of arguments!" << std::endl;

            break;
        }
        case 4:
        {
            if (splitted_comands.getSize() == 1)
            {
                if (is_opened)
                {
                    my_universe.help();
                }
                else
                    std::cout << "No file is opened" << std::endl;
            }
            else
                std::cout << "Incorrect number of arguments!" << std::endl;

            break;
        }
        case 5:
        {
            if (splitted_comands.getSize() == 2)
            {
                if (is_opened)
                {
                    if(check_names(splitted_comands[1].getArray()))
                    {
                    char planet_name[30] = ""; //1
                    strcpy(planet_name, splitted_comands[1].getArray());
                    my_universe.add_planet(planet_name);
                    }
                    else
                    {
                        break;
                    }
                }
                else
                    std::cout << "No file is opened" << std::endl;
            }
            else
                std::cout << "Incorrect number of arguments!" << std::endl;

            break;
        }
        case 6:
        {
            if (splitted_comands.getSize() == 7)
            {
                if (is_opened)
                {
                    if(check_names(splitted_comands[1].getArray())&&check_names(splitted_comands[2].getArray())&&
                        check_colour(splitted_comands[5].getArray()) && check_power(splitted_comands[6].getArray())
                            && check_rank(splitted_comands[3].getArray()) && check_age(splitted_comands[4].getArray()))
                    {
                    char planet_name[30] = ""; //1
                    char jedi_name[30] = "";   //2
                    Rank jedi_rank;            //3
                    unsigned int jedi_age = 0; //4
                    char jedi_colour[30] = ""; //5
                    double power_jedi = 0;     //6
                    strcpy(planet_name, splitted_comands[1].getArray());
                    strcpy(jedi_name, splitted_comands[2].getArray());
                    strcpy(jedi_colour, splitted_comands[5].getArray());
                    power_jedi = std::atof(splitted_comands[6].getArray()); 
                    string_to_int(splitted_comands[4], jedi_age);
                    string_to_rank(splitted_comands[3], jedi_rank);
                    if( jedi_rank > 0 && jedi_rank < 9)
                    {
                        my_universe.create_jedi(planet_name, jedi_name, jedi_age, jedi_colour, power_jedi, jedi_rank);
                    }
                    }
            
                }
                else
                    std::cout << "No file is opened" << std::endl;
            }
            else
                std::cout << "Incorrect number of arguments!" << std::endl;

            break;
        }
        case 7:
        {
            if (splitted_comands.getSize() == 3)
            {
                if (is_opened)
                {
                    if(check_names(splitted_comands[2].getArray()) && check_names(splitted_comands[1].getArray()))
                    {
                    char planet_name[30] = ""; //2
                    char jedi_name[30] = "";   //1
                    strcpy(planet_name, splitted_comands[2].getArray());
                    strcpy(jedi_name, splitted_comands[1].getArray());
                    my_universe.remove_jedi(planet_name, jedi_name);
                    }
                }
                else
                    std::cout << "No file is opened" << std::endl;
            }
            else
                std::cout << "Incorrect number of arguments!" << std::endl;

            break;
        }
        case 8:
        {
            if (splitted_comands.getSize() == 3)
            {
                if (is_opened)
                {
                    if(check_names(splitted_comands[1].getArray()) && check_power(splitted_comands[2].getArray()))
                    {
                    char jedi_name[30] = ""; //1
                    double multiplier = 0;   //2
                    strcpy(jedi_name, splitted_comands[1].getArray());
                    multiplier = std::atof(splitted_comands[2].getArray()); 
                    my_universe.promote(jedi_name, multiplier);
                    }
               
                }
                else
                    std::cout << "No file is opened" << std::endl;
            }
            else
                std::cout << "Incorrect number of arguments!" << std::endl;

            break;
        }
        case 9:
        {
            if (splitted_comands.getSize() == 3)
            {
                if (is_opened)
                {
                    if(check_names(splitted_comands[1].getArray()) && check_power(splitted_comands[2].getArray()))
                    {
                    char jedi_name[30] = ""; //1
                    double multiplier = 0;   //2
                    strcpy(jedi_name, splitted_comands[1].getArray());
                    multiplier = std::atof(splitted_comands[2].getArray()); 

                    my_universe.demote(jedi_name, multiplier);
                    }
                }
                else
                    std::cout << "No file is opened" << std::endl;
            }
            else
                std::cout << "Incorrect number of arguments!" << std::endl;

            break;
        }
        case 10:
        {
            if (splitted_comands.getSize() == 2)
            {
                if (is_opened)
                {
                    if(check_names(splitted_comands[1].getArray()))
                    {
                    char planet_name[30] = ""; //1
                    strcpy(planet_name, splitted_comands[1].getArray());
                    my_universe.get_strongest(planet_name);   
                    }

                }
                else
                    std::cout << "No file is opened" << std::endl;
            }
            else
                std::cout << "Incorrect number of arguments!" << std::endl;
            break;
        }
        case 11:
        {
            if (splitted_comands.getSize() == 3)
            {
                if (is_opened)
                {
                    if(check_names(splitted_comands[1].getArray()) && check_rank(splitted_comands[2].getArray()))
                    {
                    char planet_name[30] = ""; //1
                    Rank rank;                 //2
                    strcpy(planet_name, splitted_comands[1].getArray());
                    string_to_rank(splitted_comands[2], rank);
                    if( rank > 0 && rank < 9)
                    {
                        my_universe.get_youngest(planet_name, rank);
                    }
                   
                    }

                }
                else
                    std::cout << "No file is opened" << std::endl;
            }
            else
                std::cout << "Incorrect number of arguments!" << std::endl;

            break;
        }
        case 12:
        {
            if ((splitted_comands.getSize() >= 2) && (splitted_comands.getSize() <= 3))
            {
                if (is_opened)
                {
                    if (splitted_comands.getSize() == 3)
                    {
                        if(check_names(splitted_comands[1].getArray()) && check_rank(splitted_comands[2].getArray()))
                        {
                        char planet_name[30] = ""; //1
                        Rank rank;                 //2
                        strcpy(planet_name, splitted_comands[1].getArray());
                        string_to_rank(splitted_comands[2], rank);
                        if( rank > 0 && rank < 9)
                        {
                            my_universe.colour(planet_name, rank);    
                        }
                        }

                    }
                    else
                    {
                        if(check_names(splitted_comands[1].getArray()))
                        {
                        char planet_name[30] = ""; //1
                        strcpy(planet_name, splitted_comands[1].getArray());
                        my_universe.colour_grandMaster(planet_name); 
                        }

                    }
                }
                else
                    std::cout << "No file is opened" << std::endl;
            }
            else
                std::cout << "Incorrect number of arguments!" << std::endl;

            break;
        }
        case 13:
        { 
            if (splitted_comands.getSize() == 2)
            {
                if (is_opened)
                {
                    if(check_names(splitted_comands[1].getArray()))
                    {
                    char name[30] = ""; //1
                    strcpy(name, splitted_comands[1].getArray());
                    if (my_universe.search_jedi(name) == true)
                    {
                        my_universe.print_jedi_fromUniverse(name);
                    }
                    else if (my_universe.search_planet(name) == true)
                    {
                        my_universe.print_pl_fromUniverse(name);
                    }
                    else
                    {
                        std::cout << "There's no such jedi or planet!" << std::endl;
                    }
                    }
         
                }
                else
                    std::cout << "No file is opened" << std::endl;
            }
            else
                std::cout << "Incorrect number of arguments!" << std::endl;

            break;
        }

        case 14:
        {
            if (splitted_comands.getSize() == 3)
            {
                if (is_opened)
                {
                    if(check_names(splitted_comands[0].getArray()) && check_names(splitted_comands[2].getArray()))
                    {
                    char name1[30] = ""; //0
                    strcpy(name1, splitted_comands[0].getArray());
                    char name2[30] = ""; //2
                    strcpy(name2, splitted_comands[2].getArray());
                    my_universe.print_two_planets(name1, name2);  
                    }

                }
                else
                {
                    std::cout << "No file is opened" << std::endl;
                }
            }
            else
                std::cout << "Incorrect number of arguments!" << std::endl;

            break;
        }
        case 15:
        {
            break;
        }
        default:
        {
            
            std::cout << "No such command exists!" << std::endl;
            break;
        }
        }
    } while (strcmp(splitted_comands[0].getArray(), "exit") != 0);
    std::cout << "Exiting program..." << std::endl;
}