#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const &target);
    RobotomyRequestForm(RobotomyRequestForm const &src);
    virtual ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

    virtual void execute(Bureaucrat const &executor) const;
};
