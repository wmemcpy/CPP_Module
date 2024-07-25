#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog &src): Animal(src)
{
    *this = src;
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
        type = rhs.type;
    std::cout << "Dog assignation operator called." << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}
