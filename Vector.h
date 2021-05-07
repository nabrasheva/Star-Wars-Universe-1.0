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
    //constructors
    Vector();
    Vector(const Vector&);
    Vector<T>& operator=(const Vector&);
    ~Vector();

    void copy(const Vector&);
    void destroy();
    void resize();
    T& at(size_t)const;

    //access
    bool isEmpty() const;
    size_t getSize() const;
    size_t getCapacity() const;
    void setSizeLong(size_t);
    void setSizeShort(size_t);
    void setCapacity(size_t);
    //T operator[](size_t) const;
    T& operator[](size_t) const;

    void push_back(T&);
    void pop_back();
    void swap_elements (size_t index1, size_t index2);

    
};
/*template<typename E>
std::ostream& operator<<(std::ostream& out, const Vector<E>&);*/