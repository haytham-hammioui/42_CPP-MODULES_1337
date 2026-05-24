#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <sys/time.h>
#include <algorithm>

class PmergeMe
{
private:
    std::vector<int> _vec;
    std::deque<int>  _deq;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void parseInput(char **av);

    void sortVector();
    void sortDeque();

    void printBefore() const;
    void printAfter() const;

    size_t getSize() const;
};
