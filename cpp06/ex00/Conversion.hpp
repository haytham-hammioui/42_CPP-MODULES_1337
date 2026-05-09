#pragma once

#include <string>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <iomanip>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &other);
    public:
        static void convert (std::string str);
};