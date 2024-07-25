#pragma once

#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(Intern const &ref);
    ~Intern();

    Intern &operator=(const Intern &ref);

    AForm *makeForm(std::string const &formName, std::string const &target) const;
};

std::ostream &operator<<(std::ostream &os, Intern const &ref);
