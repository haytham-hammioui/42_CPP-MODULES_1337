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
    std::vector<int> numbers(14001, 10);
    sp2.addNumbers(numbers.begin(), numbers.end());
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    return 0;
}