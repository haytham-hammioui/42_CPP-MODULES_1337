#pragma once

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>

class Span{
private:
    std::vector<int> numbers;
    unsigned int N;
public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;
    template<typename iter>
    void addNumbers(iter begin, iter end) {
        if (numbers.size() + static_cast<unsigned int>(std::distance(begin, end)) > N) {
            throw std::runtime_error("Adding these numbers would exceed the span's capacity");
        }
        for(iter it = begin; it != end; ++it) {
            numbers.push_back(*it);
        }
    }
};