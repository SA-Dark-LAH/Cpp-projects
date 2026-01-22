#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Polymorphic Deletion Test ===" << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        delete j; // Dog destructor + Brain destructor must run
        delete i; // Cat destructor + Brain destructor must run
    }

    std::cout << "\n=== Array of Animals Test ===" << std::endl;
    {
        const int N = 10;
        Animal* animals[N];

        for (int i = 0; i < N; i++)
        {
            if (i < N / 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }

        for (int i = 0; i < N; i++)
            delete animals[i];
    }

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    {
        Dog dog1;
        dog1.setBrainIdea(0, "Eat food");

        Dog dog2 = dog1;   // Copy constructor (deep copy)

        dog2.setBrainIdea(0, "Destroy everything");

        std::cout << "dog1 idea[0]: " << dog1.getBrainIdea(0) << std::endl;
        std::cout << "dog2 idea[0]: " << dog2.getBrainIdea(0) << std::endl;
    }

    return 0;
}