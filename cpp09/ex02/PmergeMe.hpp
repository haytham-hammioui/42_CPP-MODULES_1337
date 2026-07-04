#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <ctime>
#include <algorithm>

class PmergeMe {
    public :
        PmergeMe();
        PmergeMe( const PmergeMe& other );
        PmergeMe& operator=( const PmergeMe& other );
        ~PmergeMe();
        
        void loadNumbers(int argc, char **argv);
        void executesort();
        void printResult() const;
        void printContainer(const std::vector<int>& container, const std::string& label) const;

    private :
        std::vector<int> _vectordata;
        std::deque<int>  _dequedata;
        std::vector<int> _inputnbs;
        double _vectorElapsed;
        double _dequeElapsed;

        void fordJohnsonV(std::vector<int> &seq);
        void insertVectorBinary(std::vector<int> &chain, int val, int end);

        void fordJohnsonD(std::deque<int> &seq);
        void insertDequeBinary(std::deque<int> &chain, int val, int end);

        std::vector<int> getJacobsthalOrder(int n);
};