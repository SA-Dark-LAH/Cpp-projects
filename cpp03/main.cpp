#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("CT-A");
    a.attack("Target1");
    a.takeDamage(5);
    a.beRepaired(3);
    a.takeDamage(7);
    a.beRepaired(7);
    a.beRepaired(11);
    a.takeDamage(19);
    a.attack("Target2");
    return 0;
}
