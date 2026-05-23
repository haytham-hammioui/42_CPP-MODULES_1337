#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
private:
    std::map<std::string, double> BD;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadData();
    double getValue(const std::string& date) const;

    bool isLeap(int year);
    bool isValidDate(const std::string& date);

    void processInputFile(const std::string& filename);
};