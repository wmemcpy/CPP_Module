#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <vector>

class Zombie
{
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();

    void announce() const;
    void setName(std::string name);

private:
    std::string name;
};

#endif
