#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();

    delete j;
    delete i;

    Dog dog1;
    Dog dog2 = dog1;
    Dog dog3;
    dog3 = dog1;

    return 0;
}
