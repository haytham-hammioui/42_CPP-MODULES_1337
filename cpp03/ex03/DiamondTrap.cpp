#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), name("Default"){
    std::cout << "DiamondTrap default constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name){
    std::cout << "DiamondTrap parameterized constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name){
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other){
        ClapTrap::operator=(other);
        name = other.name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}