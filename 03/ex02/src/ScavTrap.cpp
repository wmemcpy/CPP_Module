#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ScavTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " has been constructed." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " has been constructed." << std::endl;
}

ScavTrap &operator=(const ScavTrap &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " has been destructed." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (_hitPoints == 0 || _energyPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " has insufficient resources to attack!" << std::endl;
        return;
    }
    --_energyPoints;
    std::cout << "ScavTrap " << _name << " pounces on " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " has entered Gatekeeper mode." << std::endl;
}