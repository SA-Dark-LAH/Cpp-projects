#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();                      // Default constructor
    ScavTrap(const std::string& name); // Name constructor
    ScavTrap(const ScavTrap& other);   // Copy constructor
    ScavTrap& operator=(const ScavTrap& other); // Copy assignment
    ~ScavTrap();                      // Destructor

    void attack(const std::string& target); // Override
    void guardGate();                        // Special ability
};

#endif
