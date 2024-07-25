#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(PresidentialPardonForm const &src);
    virtual ~PresidentialPardonForm();

    PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

    virtual void execute(Bureaucrat const &executor) const;
};
