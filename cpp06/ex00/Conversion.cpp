#include "Conversion.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

void ScalarConverter::convert(std::string str)
{
    if (str == "nan" || str == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (str == "+inf" || str == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (str == "-inf" || str == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }

    std::string type = "";
    if (str.length() == 1 && !isdigit(str[0]))
        type = "char";
    else
    {
        size_t i = 0;
        if (str[i] == '+' || str[i] == '-')
            i++;
        bool dot = false;
        bool f = false;
        bool digit = false;
        while (i < str.length())
        {
            if (isdigit(str[i]))
                digit = true;
            else if (str[i] == '.')
            {
                if (dot)
                {
                    std::cout << "Error" << std::endl;
                    return;
                }
                dot = true;
            }
            else if (str[i] == 'f' && i + 1 == str.length() && dot)
                f = true;
            else
            {
                std::cout << "Error" << std::endl;
                return;
            }
            i++;
        }

        if (!digit)
        {
            std::cout << "Error" << std::endl;
            return;
        }
        if (dot && f)
            type = "float";
        else if (dot && !f)
            type = "double";
        else if (!dot && !f)
            type = "int";
        else
        {
            std::cout << "Error" << std::endl;
            return;
        }
    }
    
    double value;
    if (type == "char")
        value = static_cast<double>(str[0]);
    else if (type == "int")
        value = static_cast<double>(std::atoi(str.c_str()));
    else if (type == "float")
        value = static_cast<double>(std::strtof(str.c_str(), NULL));
    else if (type == "double")
        value = std::strtod(str.c_str(), NULL);
    else
    {
        std::cout << "Error" << std::endl;
        return;
    }
    
    if (value < 0 || value > 127)
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (value < 32 || value == 127)
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }

    if (value < INT_MIN || value > INT_MAX)
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }

    std::cout << "float: " << static_cast<float>(value);
    if (value == static_cast<long>(value))
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << value;
    if (value == static_cast<long>(value))
        std::cout << ".0";
    std::cout << std::endl;
}