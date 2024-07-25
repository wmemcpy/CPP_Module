#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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

    std::cout << std::endl << "---" << std::endl << std::endl;

    FragTrap myFragTrap("FT1");
    myFragTrap.attack("Target3");
    myFragTrap.takeDamage(15);
    myFragTrap.beRepaired(25);
    myFragTrap.highFivesGuys();

    return 0;
}
