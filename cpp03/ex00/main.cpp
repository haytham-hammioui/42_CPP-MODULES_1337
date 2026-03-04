#include "ClapTrap.hpp"

int main() {
    ClapTrap a;
    ClapTrap b("OMERTA");
    ClapTrap c(a);
    a = b;

    a.attack("toto");
    a.takeDamage(3);
    a.beRepaired(3);

    for (int i = 0; i < 12; i++)
        a.attack("enemy");

    a.takeDamage(50);
    a.takeDamage(50);
    a.attack("Enemy");
    a.beRepaired(5);
    return 0;
}