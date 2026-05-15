#include "Span.hpp"

int main()
{
    /*--------------------subject main---------------------*/
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    /*--------------------my main---------------------*/

    std::cout << "----------------------"<< std::endl;
    Span sp2(14000);
    std::vector<int> numbers(1400, 10);
    try {
        sp2.addNumbers(numbers.begin(), numbers.end());
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch (const std::runtime_error &e) {
        std::cerr << "Warning: " << e.what() << std::endl;
    }
    
    return 0;
}