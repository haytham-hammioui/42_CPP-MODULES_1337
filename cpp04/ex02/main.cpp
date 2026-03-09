#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal* animals[4];

    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();
    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();
    for (int i = 0; i < 4; i++)
        delete animals[i];
    return 0;
}