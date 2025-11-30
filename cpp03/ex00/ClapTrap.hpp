#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
private:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    // Orthodox Canonical Form
    ClapTrap();                                // default
    ClapTrap(const std::string& name);         // param
    ClapTrap(const ClapTrap& other);           // copy
    ClapTrap& operator=(const ClapTrap& other);// assignment
    ~ClapTrap();                               // destructor

    // Actions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP
