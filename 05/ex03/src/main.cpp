#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Intern someRandomIntern;
    AForm *rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        Bureaucrat boss("Boss", 1);
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    AForm *unknown = someRandomIntern.makeForm("unknown form", "Target");
    if (unknown)
        delete unknown;

    return 0;
}
