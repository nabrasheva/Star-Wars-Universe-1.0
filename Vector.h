#pragma once
#include <iostream>

template<typename T>
class Vector
{
    private:
    T* data;
    size_t size;
    size_t capacity;


    public:

    Vector();
    Vector(const Vector&);
    Vector<T>& operator=(const Vector&);
    ~Vector();

    void copy(const Vector&);
    void destroy();
    void resize();
    T& at(size_t)const;


    bool isEmpty() const;
    size_t getSize() const;
    size_t getCapacity() const;

    T& operator[](size_t) const;

    void push_back(const T&);
    void pop_back();
   
    void clear();

    
};
