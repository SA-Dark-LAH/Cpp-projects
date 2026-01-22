#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain* brain;                  // NEW: dynamically allocated

public:
    Dog();                         // Default constructor
    Dog(const Dog& other);         // Copy constructor
    Dog& operator=(const Dog& other); // Copy assignment
    virtual ~Dog();                // Destructor

    virtual void makeSound() const;

    // Optional for testing deep copy:
    void setBrainIdea(int index, const std::string& idea);
    std::string getBrainIdea(int index) const;
};

#endif