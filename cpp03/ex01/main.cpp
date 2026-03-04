#include "ScavTrap.hpp"

int main()
{
    std::cout << "---- Create ----" << std::endl;
    ScavTrap a("Serena");

    std::cout << "---- Attack ----" << std::endl;
    a.attack("Enemy");

    std::cout << "---- Guard Mode ----" << std::endl;
    a.guardGate();

    std::cout << "---- Copy ----" << std::endl;
    ScavTrap b = a;

    std::cout << "---- Assignment ----" << std::endl;
    ScavTrap c("Other");
    c = a;

    std::cout << "---- Destruction ----" << std::endl;
    return 0;
}