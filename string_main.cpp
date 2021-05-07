#include <iostream>
#include "String.h"
#include "String.cpp"

int main()
{
    String arr1;
    String arr2(arr1);
    arr1=arr2;
    //std::cout<<arr1.empty()<<std::endl;//
    arr1.resize();
    //std::cout<<arr1<<std::endl;;//
    //std::cout<<arr1.compare(arr2)<<std::endl;//
    arr1.push_back('c');
    //std::cout<<arr1<<std::endl;//
    arr2=arr1;
    arr1.swap(arr2);
    std::cout<<arr1<<std::endl;//
    //std::cout<<arr2<<std::endl;//
    //std::cout<<arr1.back()<<std::endl;//
    //std::cout<<arr1.front()<<std::endl;//
    //std::cout<<arr1[0]<<std::endl;//
    //std::cout<<arr1.compare(arr2)<<std::endl;//
    arr1.pop_back();
    std::cout<<arr1<<std::endl;//
    arr1.push_back('a');
    //std::cout<<arr1.compare(arr2)<<std::endl;//
    arr1.swap(arr2);
    std::cout<<arr1<<std::endl;//
    std::cout<<arr2<<std::endl;
    arr1.push_back('a');
    arr2.push_back('b');
    //std::cout<<arr1.compare(arr2)<<std::endl;//
    std::cout<<arr1<<std::endl;//
    std::cout<<arr2<<std::endl;
    //std::cout<<arr2.back()<<std::endl;//
    arr2=arr1;
    std::cout<<arr1<<std::endl;//
    std::cout<<arr2<<std::endl;//
    std::cout<<arr1.compare(arr2)<<std::endl;//
    //std::cout<<arr1.empty()<<std::endl;//
    //std::cout<<arr1.front()<<std::endl;//
    arr1.push_back('b');
    arr2.push_back('b');
    arr2.push_back('d');
    std::cout<<arr1.compare(arr2)<<std::endl;//
    std::cout<<arr1<<std::endl;//
    std::cout<<arr2<<std::endl;//
    //arr1.pop_back();
    //arr2.pop_back();
    std::cout<<arr1<<std::endl;//
    std::cout<<arr2<<std::endl;//
    std::cout<<arr2.front()<<std::endl;//
    std::cout<<arr2.back()<<std::endl;//
    //std::cout<<arr1.compare(arr2)<<std::endl;//
    return 0;
}