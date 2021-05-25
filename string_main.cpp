#include <iostream>
#include "String.h"
#include "String.cpp"
#include<cstring>
#include <stdlib.h>
#include "Jedi.h"
#include "Vector.h"
#include "Vector.cpp"
/*void string_to_int(String& arr, unsigned int& number)
{
    for(int i=0; i < arr.getSize(); i++)
    {
        char currentSymbol = arr[i];
        number*=10;
        number+= (currentSymbol - '0');
    }
}*/
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
void split(Vector<String>& splitted_comands, String& command)
{
    
    //splitted_comands.clear();
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
int main()
{

    String arr1;
    std::cin>>arr1;
    Rank rank;
    Vector<String> splitted_comands;
    split(splitted_comands, arr1);
    //std::cout<<strcmp(splitted_comands[1].getArray(), str);
    string_to_rank(splitted_comands[0], rank);
    std::cout<<rank;



    return 0;
}