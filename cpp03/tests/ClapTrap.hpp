# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap{

    std::string Name ;
    int HitPoints = 10 ;
    int EnergyPoints = 10 ;
    int AttackDamage = 0 ;

    ClapTrap();
    ClapTrap(std::string Name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

# endif