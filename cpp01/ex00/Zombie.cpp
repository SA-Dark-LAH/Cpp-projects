#include "Zombie.hpp"

Zombie::Zombie(std::string n) : name(n)
{
    std::cout << name << " is created." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed." << std::endl;
}

void Zombie::announce() const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
