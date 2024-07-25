#pragma once

#include "Bureaucrat.hpp"

class Form
{
private:
    std::string const _name;
    bool _isSigned;
    int const _toSign;
    int const _toExec;

public:
    Form();
    Form(std::string const &name, bool isSigned, int const toSign, int const toExec);
    Form(Form const &src);
    ~Form();

    Form &operator=(Form const &src);

    const std::string &getName() const;
    bool getIsSigned() const;
    int getToSign() const;
    int getToExec() const;

    void beSigned(Bureaucrat const &src);

    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, Form const &obj);
