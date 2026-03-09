#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

const WrongAnimal* roo = new WrongAnimal();
const WrongAnimal* l = new WrongCat();

l->makeSound();
roo->makeSound();

delete meta;
delete j;
delete i;
delete roo;
delete l;
return 0;
}