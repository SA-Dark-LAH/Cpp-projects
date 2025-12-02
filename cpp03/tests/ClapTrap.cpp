#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("unnamed")
{
    std::cout << "the default constructor called" << std::endl ;
}

ClapTrap::ClapTrap(std::string n) : Name(n)
{
    std::cout << "the default constructor called" << std::endl ;
}

ClapTrap::~ClapTrap()
{
    std::cout << "the destructor called for " << Name << std::endl ;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "the copy constructor called for " << Name << std::endl ;
    *this = other ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "the copy assignement operator called for " << this->Name << std::endl ;
    if(this != &other)
    {
        this->Name = other.Name;
        this->HitPoints = other.HitPoints ;
        this->EnergyPoints = other.EnergyPoints ;
        this->AttackDamage = other.AttackDamage ;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{

    if(EnergyPoints <= 0)
    {
        std::cout << "ClapTrap can't attack (energy points not enough)" << std::endl ;
        return ;
    }
    EnergyPoints -= 1 ;
    std::cout << "ClapTrap attack " << target << " and make " << AttackDamage << "of Damage ." << std::endl ;

}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(HitPoints <= 0)
    {
        std::cout << Name <<"'s hit points <= 0 so he is died and can't take damage" << std::endl ;
        return ;
    }
    HitPoints -= amount ;
    std::cout << Name << " got damaged by " << amount << " and his hp now is " << HitPoints << std::endl ;
}

void ClapTrap::beRepaired(unsigned int amount)
{

    if(EnergyPoints <= 0)
    {
        std::cout << "ClapTrap can't repair (energy points not enough)" << std::endl ;
        return ;
    }
    EnergyPoints -= 1 ;
    HitPoints += amount ;
    std::cout << "ClapTrap repaired hitpoints by " << amount << "hitpoints are now " << HitPoints << std::endl ;
}