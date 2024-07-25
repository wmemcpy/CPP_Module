#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", false, 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("Robotomy Request Form", false, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src), _target(src._target)
{
    if (this != &src)
        *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
    if (this != &src)
        _target = src._target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw NotSignedException();
    if (executor.getGrade() > getToExec())
        throw GradeTooLowException();
    std::cout << "* drilling noises * https://youtu.be/e839iBeupx4 * drilling noises *" << std::endl;

    srand(time(NULL));
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << _target << " robotomization failed" << std::endl;
}