#include "Conversion.hpp"

int main(int ac, char **av){
    if(ac == 2){
        ScalarConverter::convert(av[1]);
        return 0;
    }
    std::cout << "invalid input" << std::endl;
    return 1;
}