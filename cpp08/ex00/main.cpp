#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "Value found: " << *it << std::endl;
    } 
    catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}