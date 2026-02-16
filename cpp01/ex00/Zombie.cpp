#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie(){
    std::cout << "Zombie " << this->name << " is destroyed." << std::endl;
}

void Zombie::announce() const{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

