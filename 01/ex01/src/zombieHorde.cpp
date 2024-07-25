#include "Zombie.hpp"
#include <new>
#include <iostream>

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *zombies = new Zombie[N];
    if (!zombies)
    {
        std::cerr << "Failed to allocate memory for zombies" << std::endl;
        return NULL;
    }
    for (int i = 0; i < N; ++i)
        zombies[i].setName(name);
    return zombies;
}
