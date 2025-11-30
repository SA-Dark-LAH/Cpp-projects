#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap constructor called for " << this->name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    // ClapTrap copy constructor takes care of copying base members
    std::cout << "FragTrap copy constructor called for " << this->name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other); // reuse base assignment
    }
    std::cout << "FragTrap assignment operator called for " << this->name << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << this->name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (this->hitPoints == 0)
    {
        std::cout << "FragTrap " << this->name << " is dead and can't ask for a high five." << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->name << " requests a positive high five!" << std::endl;
}
