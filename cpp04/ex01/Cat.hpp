#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain* brain;                      // dynamically allocated

public:
    Cat();                             // Default constructor
    Cat(const Cat& other);             // Copy constructor
    Cat& operator=(const Cat& other);  // Assignment operator
    virtual ~Cat();                    // Destructor

    virtual void makeSound() const;

    // Optional helpers for testing deep copy
    void setBrainIdea(int index, const std::string& idea);
    std::string getBrainIdea(int index) const;
};

#endif
