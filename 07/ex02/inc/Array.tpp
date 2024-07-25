#include <stdexcept>
#include <climits>

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
    if (_array == NULL)
        throw std::bad_alloc();
}

template <typename T>
Array<T>::Array(const Array &other)
{
    if (this != &other)
    {
        _size = other._size;
        _array = new T[_size];
        if (_array == NULL)
            throw std::bad_alloc();

        for (unsigned int i = 0; i < _size; ++i)
            _array[i] = other._array[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] _array;
        _size = other._size;
        _array = new T[_size];
        if (_array == NULL)
            throw std::bad_alloc();

        for (unsigned int i = 0; i < _size; ++i)
            _array[i] = other._array[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    if (_array != NULL)
        delete[] _array;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _array[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}
