#pragma once
#include "String.h"
#include <iostream>
#include <cassert>
void String::destroy()
{
    delete[] arr;
}
void String::copy(const String &other)
{
    this->destroy();
    this->size = other.size;
    this->capacity = other.capacity;
    this->arr = new (std::nothrow) char[other.capacity];
    if (this->arr == nullptr)
    {
        std::cout << "Could not allocate memory for array." << std::endl;
    }
    else
    {
        for (int i = 0; i < other.size; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }
}
String::String()
{

    this->capacity = 21;
    this->size = 0;
    this->arr = new (std::nothrow) char[this->capacity];
    if (this->arr == nullptr)
    {
        std::cout << "Could not allocate memory for array." << std::endl;
    }
}

String::String(const char *_arr, const unsigned int &_size, const unsigned int &_capacity)
{

    if ((_size < _capacity) && (_arr != nullptr))
    {
        this->size = _size;
        this->capacity = _capacity;
        this->arr = new (std::nothrow) char[_capacity];
        if (this->arr == nullptr)
        {
            std::cout << "Could not allocate memory for array." << std::endl;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                this->arr[i] = _arr[i];
            }
        }
    }
}

String::String(const String &other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    this->arr = new (std::nothrow) char[other.capacity];
    if (this->arr == nullptr)
    {
        std::cout << "Could not allocate memory for array." << std::endl;
    }
    else
    {
        for (int i = 0; i < other.size; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }
}

String &String::operator=(const String &other)
{
    if (this != &other)
    {
        this->copy(other);
    }

    return *this;
}

String::~String()
{
    this->destroy();
}

char &String::at(unsigned int i)
{
    assert(i < size);
    return this->arr[i];
}

char &String::operator[](unsigned int i)
{
    return this->at(i);
}

void String::resize()
{
    this->capacity *= 2;
    char *newBuffer = new char[this->capacity];
    for (int i = 0; i < this->size; i++)
    {
        newBuffer[i] = this->arr[i];
    }
    this->destroy();
    this->arr = newBuffer;
}

void String::push_back(const char &newElem)
{
    if (this->size == this->capacity)
    {
        this->resize();
    }
    this->size++;
    this->arr[this->size - 1] = newElem;
}
void String::pop_back()
{
    this->size--;
}

const char &String::back() const
{
    return arr[this->size - 1];
}
const char &String::front() const
{
    return arr[0];
}
void String::swap(String &other)
{
    String helper;
    helper.copy(*this);
    this->copy(other);
    other.copy(helper);
}
int String::compare(const String &other) const
{
    if (this->size == other.size)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->arr[i] < other.arr[i])
            {
                return (this->arr[i] - other.arr[i]);
            }

            if (this->arr[i] > other.arr[i])
            {
                return (this->arr[i] - other.arr[i]);
            }
        }
        return 0;
    }

    else if (this->size < other.size)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->arr[i] < other.arr[i])
            {
                return (this->arr[i] - other.arr[i]);
            }

            if (this->arr[i] > other.arr[i])
            {
                return (this->arr[i] - other.arr[i]);
            }
        }
        return (this->size - other.size);
    }

    else
    {
        for (int i = 0; i < other.size; i++)
        {
            if (this->arr[i] < other.arr[i])
            {
                return (this->arr[i] - other.arr[i]);
            }

            if (this->arr[i] > other.arr[i])
            {
                return (this->arr[i] - other.arr[i]);
            }
        }
        return (this->size - other.size);
    }
}
bool String::empty() const
{
    return (this->size == 0);
}

std::ostream &operator<<(std::ostream &out, const String &item)
{
    for (int i = 0; i < item.size; i++)
    {
        out << item.arr[i];
    }
    return out;
}