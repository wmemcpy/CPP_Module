#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap myClapTrap("CT1");
    myClapTrap.attack("Target1");
    myClapTrap.takeDamage(3);
    myClapTrap.beRepaired(5);

    std::cout << std::endl << "---" << std::endl << std::endl;

    ScavTrap myScavTrap("ST1");
    myScavTrap.attack("Target2");
    myScavTrap.takeDamage(10);
    myScavTrap.beRepaired(20);
    myScavTrap.guardGate();

    return 0;
}