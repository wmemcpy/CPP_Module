#include "Dog.hpp"

Dog::Dog(): brain(new Brain())
{
    type = "Dog";
    std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog &src): Animal(src), brain(new Brain())
{
    std::cout << "Dog copy constructor called." << std::endl;
    *this = src;
}

Dog &Dog::operator=(const Dog &src)
{
    if (this != &src)
    {
        type = src.type;
        *brain = *src.brain;
    }
    std::cout << "Dog assignation operator called." << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}
