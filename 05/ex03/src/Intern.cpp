#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(Intern const &ref)
{
    if (this != &ref)
        *this = ref;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &ref)
{
    if (this != &ref)
        *this = ref;
    return *this;
}

AForm *createShrubberyCreationForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *createRobotomyRequestForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *createPresidentialPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    struct FormPair
    {
        const char *name;

        AForm *(*formCreator)(const std::string &);
    };

    FormPair formPairs[] = {{"shrubbery creation", &createShrubberyCreationForm},
                            {"robotomy request", &createRobotomyRequestForm},
                            {"presidential pardon", &createPresidentialPardonForm}};

    for (size_t i = 0; i < sizeof(formPairs) / sizeof(FormPair); ++i)
    {
        if (formName == formPairs[i].name)
        {
            std::cout << "Intern creates " << formPairs[i].name << std::endl;
            return formPairs[i].formCreator(target);
        }
    }

    std::cout << "Intern cannot create " << formName << " because the form name is invalid." << std::endl;
    return NULL;
}

std::ostream &operator<<(std::ostream &os, Intern const &ref)
{
    (void)ref;
    os << "Intern";
    return os;
}
