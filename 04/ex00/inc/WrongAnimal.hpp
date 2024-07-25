#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &src);
    WrongAnimal &operator=(const WrongAnimal &rhs);
    virtual ~WrongAnimal();

    virtual std::string getType() const;
    virtual void makeSound() const;

protected:
    std::string type;
};

#endif // WRONGANIMAL_HPP
