#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== CORRECT POLYMORPHISM ===" << std::endl;

    const Animal* meta = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();

    std::cout << d->getType() << std::endl;
    std::cout << c->getType() << std::endl;

    d->makeSound();  // dog sound
    c->makeSound();  // cat sound
    meta->makeSound();  // Animal sound

    delete meta;
    delete d;
    delete c;

        std::cout << std::endl;
    std::cout << "=== WRONG POLYMORPHISM ===" << std::endl;

    const WrongAnimal* w = new WrongCat();
    std::cout << w->getType() << std::endl;

    w->makeSound();  // WRONG: prints WrongAnimal sound

    delete w;

    return (0) ;
}