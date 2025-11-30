#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap c("CT");
    FragTrap f("FT");

    std::cout << std::endl;

    // Test ClapTrap
    c.attack("Target");
    c.takeDamage(5);
    c.beRepaired(3);

    std::cout << std::endl;

    // Test FragTrap
    f.attack("Enemy");
    f.takeDamage(20);
    f.beRepaired(10);
    f.highFivesGuys();

    std::cout << std::endl;

    return 0;
}
