#include "Harl.hpp"

int main()
{
    Harl h;

    h.complain("DEBUG");
    std::cout << std::endl;
    h.complain("INFO");
    std::cout << std::endl;
    h.complain("WARNING");
    std::cout << std::endl;
    h.complain("ERROR");
}
