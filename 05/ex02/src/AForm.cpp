#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _isSigned(false), _toSign(130), _toExec(100) {}

AForm::AForm(std::string const &name, bool isSigned, int const toSign, int const toExec) : _name(name), _isSigned(isSigned), _toSign(toSign), _toExec(toExec)
{
    if (_toSign < 1 || _toExec < 1)
        throw GradeTooHighException();
    else if (_toSign > 150 || _toExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(AForm const &src) : _name(src._name), _isSigned(src._isSigned), _toSign(src._toSign), _toExec(src._toExec)
{
    if (this != &src)
        *this = src;
}

AForm::~AForm() {}

AForm &AForm::operator=(AForm const &src)
{
    if (this != &src)
        _isSigned = src._isSigned;
    return *this;
}

const std::string &AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getToSign() const
{
    return _toSign;
}

int AForm::getToExec() const
{
    return _toExec;
}

void AForm::beSigned(Bureaucrat const &src)
{
    if (src.getGrade() > _toSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm::Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm::Grade too low";
}

const char *AForm::NotSignedException::what() const throw()
{
    return "AForm::Form not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "AForm " << form.getName() << " is " << (form.getIsSigned() ? "signed" : "not signed")
        << ", grade required to sign: " << form.getToSign() << ", grade required to execute: " << form.getToExec()
        << ".";
    return out;
}
