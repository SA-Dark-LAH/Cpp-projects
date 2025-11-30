#include "ClapTrap.hpp"
#include <iostream>

// Default constructor (useful for OCF)
ClapTrap::ClapTrap()
    : name("Unnamed"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap default constructor called for " << name << std::endl;
}

// Parameter constructor
ClapTrap::ClapTrap(const std::string& n)
    : name(n), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap constructor called for " << name << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), hitPoints(other.hitPoints),
      energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap copy constructor called for " << name << std::endl;
}

// Copy assignment
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap assignment operator called for " << name << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for " << name << std::endl;
}

// attack: costs 1 energy, requires hitPoints>0 and energyPoints>0
void ClapTrap::attack(const std::string& target)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is dead and can't attack.\n";
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy to attack.\n";
        return;
    }
    energyPoints -= 1;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!\n";
}

// takeDamage: reduce hitPoints but never underflow
void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is already at 0 HP.\n";
        return;
    }
    if (amount >= hitPoints)
        hitPoints = 0;
    else
        hitPoints -= amount;

    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage, HP is now " << hitPoints << ".\n";
}

// beRepaired: costs 1 energy, requires hitPoints>0 and energyPoints>0
void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is dead and can't be repaired.\n";
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy to repair.\n";
        return;
    }
    energyPoints -= 1;
    // simple heal: add amount to hitPoints
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount
              << " points, HP is now " << hitPoints << ".\n";
}
