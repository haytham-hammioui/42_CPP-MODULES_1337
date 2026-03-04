#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
    std::cout << "ScavTrap default constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    std::cout << "ScavTrap parameterized constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other){
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other){
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if (energyPoints > 0 && hitPoints > 0){
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "ScavTrap " << name << " cannot attack!" << std::endl;
    }
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
