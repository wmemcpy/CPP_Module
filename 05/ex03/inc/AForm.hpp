#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    std::string const _name;
    bool _isSigned;
    int const _toSign;
    int const _toExec;

public:
    AForm();
    AForm(std::string const &name, bool isSigned, int const toSign, int const toExec);
    AForm(AForm const &src);
    virtual ~AForm();

    AForm &operator=(AForm const &src);

    const std::string &getName() const;
    bool getIsSigned() const;
    int getToSign() const;
    int getToExec() const;

    void beSigned(Bureaucrat const &src);

    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class NotSignedException : public std::exception
    {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, AForm const &obj);
