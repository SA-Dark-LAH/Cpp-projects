#include "ScavTrap.hpp"
#include <iostream>

/* Default constructor */
ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

/* Name constructor */
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap constructor called for " << this->name << std::endl;
}

/* Copy constructor */
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    *this = other;
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

/* Copy assignment */
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

/* Destructor */
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << this->name << std::endl;
}

/* Override attack */
void ScavTrap::attack(const std::string& target)
{
    if (this->hitPoints <= 0 || this->energyPoints <= 0)
    {
        std::cout << "ScavTrap " << this->name << " can't attack." << std::endl;
        return;
    }

    this->energyPoints--;
    std::cout << "ScavTrap " << this->name << " attacks "
              << target << ", causing "
              << this->attackDamage << " points of damage!"
              << std::endl;
}

/* Special ability */
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode."
              << std::endl;
}