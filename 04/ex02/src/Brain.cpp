#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        ideas[0] = "Idea";
    std::cout << "Brain constructor called." << std::endl;
}

Brain::Brain(const Brain &src)
{
    for (int i = 0; i < 100; ++i)
        this->ideas[i] = src.ideas[i];
    std::cout << "Brain copy constructor called." << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
    if (this != &src)
    {
        for (int i = 0; i < 100; ++i)
            this->ideas[i] = src.ideas[i];
    }
    std::cout << "Brain assignation operator called." << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called." << std::endl;
}
