#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const Animal &src) : type(src.type)
{
    std::cout << "Animal copy constructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
    if (this == &src)
        return *this;
    type = src.type;
    std::cout << "Animal assignation operator called." << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called." << std::endl;
}

std::string Animal::getType() const
{
    return type;
}
