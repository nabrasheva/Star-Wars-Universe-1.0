#pragma once
#include <iostream>
class String
{
private:
    char *arr;
    unsigned int capacity;
    unsigned int size;

    void destroy();

    void copy(const String &);

public:
    //big 4
    String();
    String(const char *, const unsigned int &, const unsigned int &);
    String(const String &);
    String &operator=(const String &);
    ~String();

    char &at(unsigned int);
    char &operator[](unsigned int);

    void resize();
    void push_back(const char &);
    void pop_back();

    const char &back() const;
    const char &front() const;
    void swap(String &);

    int compare(const String&) const;
    bool empty() const;
    friend std::ostream &operator<<(std::ostream &, const String &);
};