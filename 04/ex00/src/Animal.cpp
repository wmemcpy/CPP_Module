#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const Animal &src)
{
    *this = src;
    std::cout << "Animal copy constructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
    if (this != &rhs)
        type = rhs.type;
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

void Animal::makeSound() const
{
    std::cout << "Animal makes a sound." << std::endl;
}
