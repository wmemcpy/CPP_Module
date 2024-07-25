#include "Form.hpp"

Form::Form() : _name("Form"), _isSigned(false), _toSign(130), _toExec(100) {}

Form::Form(std::string const &name, bool isSigned, int const toSign, int const toExec) : _name(name), _isSigned(isSigned), _toSign(toSign), _toExec(toExec)
{
    if (_toSign < 1 || _toExec < 1)
        throw GradeTooHighException();
    else if (_toSign > 150 || _toExec > 150)
        throw GradeTooLowException();
}

Form::Form(Form const &src) : _name(src._name), _isSigned(src._isSigned), _toSign(src._toSign), _toExec(src._toExec)
{
    if (this != &src)
        *this = src;
}

Form::~Form() {}

Form &Form::operator=(Form const &src)
{
    if (this != &src)
        _isSigned = src._isSigned;
    return *this;
}

const std::string &Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getToSign() const
{
    return _toSign;
}

int Form::getToExec() const
{
    return _toExec;
}

void Form::beSigned(Bureaucrat const &src)
{
    if (src.getGrade() > _toSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form::Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form::Grade too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form " << form.getName() << " is " << (form.getIsSigned() ? "signed" : "not signed")
        << ", grade required to sign: " << form.getToSign() << ", grade required to execute: " << form.getToExec()
        << ".";
    return out;
}
