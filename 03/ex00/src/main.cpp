#include "ClapTrap.hpp"

int main()
{
    ClapTrap myClapTrap("CT1");
    myClapTrap.attack("Target1");
    myClapTrap.takeDamage(3);
    myClapTrap.beRepaired(5);

    return 0;
}