#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout << "ClapTrap " << name << " created with default constructor." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout << "ClapTrap " << name << " created with parameterized constructor." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage){
    std::cout << "ClapTrap " << name << " created with copy constructor." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << name << " assigned with copy assignment operator." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "ClapTrap " << name << " cannot attack. Not enough energy or hit points." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already destroyed." << std::endl;
        return;
    }
    if (amount >= hitPoints) {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and is destroyed!" << std::endl;
    }
    else {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining hit points: " << hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (hitPoints > 0 && energyPoints > 0) {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " is repaired by " << amount << " points! Current hit points: " << hitPoints << std::endl;
    }
    else {
        std::cout << "ClapTrap " << name << " cannot be repaired. Not enough hit points or energy." << std::endl;
    }
}
