#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    try {
        PmergeMe p;
        p.loadNumbers(ac, av);
        p.executesort();
        p.printResult();
    } catch(std::exception& e) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    return 0;
}