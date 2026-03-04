#include "DiamondTrap.hpp"

int main()
{
    std::cout << "---- Create FragTrap ----" << std::endl;
    DiamondTrap a("OMERTA");

    std::cout << "---- Attack ----" << std::endl;
    a.attack("Enemy");

    std::cout << "----  ----" << std::endl;
    a.whoAmI();

    std::cout << "---- Copy ----" << std::endl;
    DiamondTrap b = a;

    std::cout << "---- Assignment ----" << std::endl;
    DiamondTrap c("Other");
    c = a;

    std::cout << "---- End of program ----" << std::endl;
    return 0;
}