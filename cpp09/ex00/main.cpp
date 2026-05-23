#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac == 2){
        BitcoinExchange btc;
        btc.loadData();
        btc.processInputFile(av[1]);
        return 0;
    }
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
}