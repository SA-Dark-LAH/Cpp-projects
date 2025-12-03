#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap c("Clap1");
    FragTrap f("Frag1");

    std::cout << std::endl;

    c.attack("Target");
    c.takeDamage(5);
    c.beRepaired(3);

    std::cout << std::endl;

    f.attack("Enemy");
    f.takeDamage(20);
    f.beRepaired(10);
    f.highFivesGuys();

    std::cout << std::endl;

    return 0;
}
