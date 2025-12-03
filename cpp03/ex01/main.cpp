#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap a("Clap-1");
    ScavTrap b("Scav-1");

    std::cout << std::endl;

    a.attack("Target-1");
    a.takeDamage(5);
    a.beRepaired(3);

    std::cout << std::endl;

    b.attack("Target-2");
    b.takeDamage(30);
    b.beRepaired(10);
    b.guardGate();

    std::cout << std::endl;

    return 0;
}
