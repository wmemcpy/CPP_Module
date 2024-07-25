#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat high("Alice", 1);
        std::cout << high << std::endl;
        high.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat low("Bob", 150);
        std::cout << low << std::endl;
        low.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat perfect("Charlie", 75);
        std::cout << perfect << std::endl;
        perfect.incrementGrade();
        std::cout << perfect << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
