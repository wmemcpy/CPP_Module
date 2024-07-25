#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " has been constructed." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " has been constructed." << std::endl;
}

FragTrap &operator=(const FragTrap &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " has been destructed." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (_hitPoints == 0 || _energyPoints == 0)
    {
        std::cout << "FragTrap " << _name << " has insufficient resources to attack!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name << " pounces on " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " requests high fives!" << std::endl;
}
