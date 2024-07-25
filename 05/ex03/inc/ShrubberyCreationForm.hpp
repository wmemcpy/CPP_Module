#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const &target);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    virtual ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

    virtual void execute(Bureaucrat const &executor) const;
};
