#include "iter.hpp"
#include <iostream>

void multiplyByTwo(int &x)
{
    x *= 2;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = 5;

    std::cout << "Integer array before iter:" << std::endl;
    for (size_t i = 0; i < intArrayLength; ++i)
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    iter(intArray, intArrayLength, multiplyByTwo);

    std::cout << "Integer array after iter:" << std::endl;
    for (size_t i = 0; i < intArrayLength; ++i)
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}