#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat &src): Animal(src)
{
    *this = src;
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
        type = rhs.type;
    std::cout << "Cat assignation operator called." << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}
