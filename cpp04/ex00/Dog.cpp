#include "Dog.hpp"

// Default constructor
Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = other.type;
}

// Copy assignment operator
Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

// Destructor
Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

// Overridden sound
void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}
