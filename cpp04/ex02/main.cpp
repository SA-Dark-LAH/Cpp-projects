#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // Animal a;                      // ERROR: cannot instantiate abstract class

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    dog->makeSound();  // Woof
    cat->makeSound();  // Meow

    delete dog;
    delete cat;

    return 0;
}