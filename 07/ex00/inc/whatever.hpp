#pragma once

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T &min(T const &a, T const &b)
{
    return (a < b) ? a : b;
}

template <typename T>
const T &max(T const &a, T const &b)
{
    return (a > b) ? a : b;
}
