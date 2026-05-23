#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): BD(other.BD){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        BD = other.BD;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData()
{
    std::ifstream file("data.csv");

    if (!file.is_open())
    {
        std::cerr << "Error: could not open data.csv" << std::endl;
        return;
    }

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t pos = line.find(',');

        if (pos == std::string::npos)
            continue;

        std::string date = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        double val = std::strtod(value.c_str(), NULL);

        BD[date] = val;
    }
}

double BitcoinExchange::getValue(const std::string& date) const
{
    if (BD.empty())
        throw std::runtime_error("Database is empty");

    std::map<std::string, double>::const_iterator it = BD.lower_bound(date);

    if (it != BD.end() && it->first == date)
        return it->second;

    if (it == BD.begin())
        throw std::runtime_error("Error: date too early");

    --it;

    return it->second;
}

bool BitcoinExchange::isLeap(int year)
{
    return ((year % 4 == 0 && year % 100 != 0)
        || (year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.size() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] =
    {
        31,28,31,30,31,30,
        31,31,30,31,30,31
    };

    if (month == 2 && isLeap(year))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (line.empty()
            || line.find_first_not_of(" \t\r\n")
            == std::string::npos)
            continue;

        size_t pos = line.find('|');

        if (pos == std::string::npos)
        {
            std::cerr << "Error: bad input => "
                      << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pos);
        std::string valueStr = line.substr(pos + 1);

        date.erase(date.find_last_not_of(" \t") + 1);
        date.erase(0, date.find_first_not_of(" \t"));

        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));

        if (date.empty() || valueStr.empty())
        {
            std::cerr << "Error: bad input => "
                      << line << std::endl;
            continue;
        }

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => "
                      << date << std::endl;
            continue;
        }

        char* end;

        double value = std::strtod(valueStr.c_str(), &end);

        if (*end != '\0')
        {
            std::cerr << "Error: bad input => "
                      << valueStr << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cerr << "Error: not a positive number."
                      << std::endl;
            continue;
        }

        if (value > 1000)
        {
            std::cerr << "Error: too large a number."
                      << std::endl;
            continue;
        }

        try
        {
            double rate = getValue(date);

            std::cout << date
                      << " => "
                      << value
                      << " = "
                      << value * rate
                      << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}