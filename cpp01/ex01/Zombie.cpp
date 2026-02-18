#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie(){
    if (!this->name.empty())
        std::cout << "Zombie " << this->name << " is destroyed." << std::endl;
}

void Zombie::announce() const{
    if (!this->name.empty())
        std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
