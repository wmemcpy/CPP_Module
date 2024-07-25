#include "Cat.hpp"

Cat::Cat(): brain(new Brain())
{
    type = "Cat";
    std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat &src): Animal(src), brain(new Brain())
{
    std::cout << "Cat copy constructor called." << std::endl;
    *this = src;
}

Cat &Cat::operator=(const Cat &src)
{
    if (this != &src)
    {
        type = src.type;
        *brain = *src.brain;
    }
    std::cout << "Cat assignation operator called." << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}
