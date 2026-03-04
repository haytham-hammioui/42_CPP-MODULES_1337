#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
    std::cout << "FragTrap default constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    std::cout << "FragTrap parameterized constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other){
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other){
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other){
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target){
    if (energyPoints > 0 && hitPoints > 0){
        std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "FragTrap " << name << " cannot attack!" << std::endl;
    }
}

void FragTrap::highFivesGuys(){
    std::cout << "FragTrap " << name << " is requesting a high five!" << std::endl;
}
