#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    Zombie *zombie = newZombie("Zombie1");
    zombie->announce();
    delete zombie;

    randomChump("RandomZombie");

    return 0;
}
