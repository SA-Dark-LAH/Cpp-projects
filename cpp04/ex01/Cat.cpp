#include "Cat.hpp"

// Default constructor
Cat::Cat() : brain(new Brain())
{
    this->type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

// Copy constructor (deep copy)
Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);   // Deep copy
}

// Assignment operator (deep copy)
Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;

    if (this != &other)
    {
        this->type = other.type;

        delete this->brain;            // Free old brain
        this->brain = new Brain(*other.brain);  // Deep copy
    }

    return *this;
}

// Destructor
Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

// Optional deep copy testing helpers
void Cat::setBrainIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}

std::string Cat::getBrainIdea(int index) const
{
    return brain->getIdea(index);
}
