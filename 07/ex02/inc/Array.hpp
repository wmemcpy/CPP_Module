#pragma once

#include <cstdlib>

template <typename T>
class Array
{
private:
    T *_array;
    unsigned int _size;

public:
    Array();
    Array(unsigned int n);
    Array(Array const &src);
    ~Array();

    Array &operator=(Array const &rhs);

    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;
    unsigned int size() const;
};

#include "Array.tpp"
