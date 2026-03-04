#include "FragTrap.hpp"

int main()
{
    std::cout << "---- Create FragTrap ----" << std::endl;
    FragTrap a("OMERTA");

    std::cout << "---- Attack ----" << std::endl;
    a.attack("Enemy");

    std::cout << "---- High Five ----" << std::endl;
    a.highFivesGuys();

    std::cout << "---- Copy ----" << std::endl;
    FragTrap b = a;

    std::cout << "---- Assignment ----" << std::endl;
    FragTrap c("Other");
    c = a;

    std::cout << "---- End of program ----" << std::endl;
    return 0;
}