#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", false, 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("Presidential Pardon Form", false, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src), _target(src._target)
{
    if (this != &src)
        *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
    if (this != &src)
        _target = src._target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > getToExec())
        throw GradeTooLowException();
    std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &src)
{
    os << src.getName() << " is " << (src.getIsSigned() ? "signed" : "not signed") << " and requires a grade " << src.getToSign() << " to sign and a grade " << src.getToExec() << " to execute." << std::endl;
    return os;
}
