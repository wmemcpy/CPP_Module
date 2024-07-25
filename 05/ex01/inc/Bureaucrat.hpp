#pragma once

#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(std::string const &name, int grade);
    Bureaucrat(Bureaucrat const &src);

    ~Bureaucrat();

    Bureaucrat &operator=(Bureaucrat const &src);

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(Form &src);

    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj);
