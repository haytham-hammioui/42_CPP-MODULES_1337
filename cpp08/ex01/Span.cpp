#include "Span.hpp"

Span::Span(unsigned int N) : numbers(), N(N) {}

Span::Span(const Span& other) : numbers(other.numbers), N(other.N) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        numbers = other.numbers;
        N = other.N;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (numbers.size() >= N) {
        throw std::runtime_error("Span is full");
    }
    numbers.push_back(number);
}

int Span::shortestSpan() const{
    if(numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span");
    }
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int shortest = sortedNumbers[1] - sortedNumbers[0];
    for(size_t i = 1; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if(span < shortest) {
            shortest = span;
        }
    }
    return shortest;
}

int Span::longestSpan() const {
    if(numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span");
    }
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return max - min;
}

