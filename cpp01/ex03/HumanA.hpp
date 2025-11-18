#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon& weapon; //must always exist

public:
    HumanA(std::string name, Weapon& weapon);//constructor that set the name and the ref
    void attack() const;
};

#endif