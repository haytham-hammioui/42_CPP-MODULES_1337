#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    std::cout << "\n===== INT ARRAY =====" << std::endl;
    Array<int> numbers(5);

    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;

    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

    std::cout << "\n===== STRING ARRAY =====" << std::endl;
    Array<std::string> words(3);

    words[0] = "hello";
    words[1] = "cpp";
    words[2] = "templates";

    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << "words[" << i << "] = " << words[i] << std::endl;

    std::cout << "\n===== OUT OF BOUNDS TEST =====" << std::endl;

    try
    {
        std::cout << numbers[100] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}