#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
    this->type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

// Copy constructor (deep copy)
Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);   // calls the brain's copy contructor to create a deep copy
}

// Assignment operator (deep copy)
Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;

    if (this != &other)
    {
        // Copy parent attributes
        this->type = other.type;

        // Delete existing brain to avoid leaks
        delete this->brain;

        // Allocate a new deep-copied brain
        this->brain = new Brain(*other.brain); //calls the brain's copy contructor to create a deep copy
    }

    return *this;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

// Optional: Deep copy testing helpers
void Dog::setBrainIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}

std::string Dog::getBrainIdea(int index) const
{
    return brain->getIdea(index);
}