#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vectorElapsed(0.0), _dequeElapsed(0.0) {}
 
PmergeMe::PmergeMe( const PmergeMe& other ) 
        : _vectordata(other._vectordata), _dequedata(other._dequedata),
        _inputnbs(other._inputnbs),
        _vectorElapsed(other._vectorElapsed), _dequeElapsed(other._dequeElapsed)
        {}
 
PmergeMe& PmergeMe::operator=( const PmergeMe& other ) {
    if (this != &other) {
        _vectordata = other._vectordata;
        _dequedata = other._dequedata;
        _inputnbs = other._inputnbs;
        _vectorElapsed = other._vectorElapsed;
        _dequeElapsed = other._dequeElapsed;
    }
    return *this;
}
 
PmergeMe::~PmergeMe() {}


void PmergeMe::loadNumbers(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        std::string token(argv[i]);

        if (token.empty())
            throw std::runtime_error("empty token");

        for (size_t j = 0; j < token.size(); ++j) {
            if (!std::isdigit(static_cast<unsigned char>(token[j])))
                throw std::runtime_error("invalid character: " + token);
        }

        long val = std::strtol(token.c_str(), NULL, 10);
        if (val <= 0 || val > INT_MAX)
            throw std::runtime_error("out of range: " + token);

        int num = static_cast<int>(val);
        _vectordata.push_back(num);
        _dequedata.push_back(num);
        _inputnbs.push_back(num);
    }

    if (_vectordata.empty() || _dequedata.empty() || _inputnbs.empty())
        throw std::runtime_error("no input");
}


std::vector<int> PmergeMe::getJacobsthalOrder(int n) { //start by 0 and 1 and next Jn = J(n-1) + 2 * J(n-2)
    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (jacob.back() < n)
        jacob.push_back(jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2]);

    std::vector<int> order;
    for (size_t k = 1; k < jacob.size(); ++k) {
        int high = std::min(jacob[k], n);
        int low = jacob[k-1] + 1;
        for (int idx = high; idx >= low; --idx)
            order.push_back(idx);
        if (high >= n) break;
    }
    return order;
}


void PmergeMe::insertVectorBinary(std::vector<int> &chain, int val, int end) {
    int left = 0, right = end;
    while (left != right) {
        int mid = left + (right - left) / 2;
        if (chain[mid] < val)
            left = mid + 1;
        else
            right = mid;
    }
    chain.insert(chain.begin() + left, val);
}

void PmergeMe::insertDequeBinary(std::deque<int> &chain, int val, int end) {
    int left = 0, right = end;
    while (left != right) {
        int mid = left + (right - left) / 2;
        if (chain[mid] < val)
            left = mid + 1;
        else
            right = mid;
    }
    chain.insert(chain.begin() + left, val);
}

 
void PmergeMe::fordJohnsonV(std::vector<int> &seq) {
    int n = static_cast<int>(seq.size());
    if (n <= 1)
        return;
 
    bool hasStraggler = (n % 2 != 0);
    int  leftover    = hasStraggler ? seq[n - 1] : 0;

    std::vector<std::pair<int,int> > nbpairs;
    int pairLimit = n - (hasStraggler ? 1 : 0);
    for (int i = 0; i + 1 < pairLimit; i += 2) {
        if (seq[i] >= seq[i + 1])
            nbpairs.push_back(std::make_pair(seq[i], seq[i + 1]));
        else
            nbpairs.push_back(std::make_pair(seq[i + 1], seq[i]));
    }
 
    std::vector<int> mainChain;
    for (std::vector<std::pair<int, int> >::iterator it = nbpairs.begin();
        it != nbpairs.end();
        ++it)
    {
        mainChain.push_back(it->first);
    }
 
    fordJohnsonV(mainChain);
 
    std::vector<std::pair<int,int> > sortedPairs;
    std::vector<std::pair<int,int> > unsortedPairs = nbpairs;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < unsortedPairs.size(); ++j) {
            if (unsortedPairs[j].first == mainChain[i]) {
                sortedPairs.push_back(unsortedPairs[j]);
                unsortedPairs.erase(unsortedPairs.begin() + j);
                break;
            }
        }
    }

    std::vector<int> resultChain;
    resultChain.push_back(sortedPairs[0].second);
    for (size_t i = 0; i < sortedPairs.size(); ++i)
        resultChain.push_back(sortedPairs[i].first);

    int pendCount = static_cast<int>(sortedPairs.size()) - 1;
    if (pendCount > 0) {
        std::vector<int> order = getJacobsthalOrder(pendCount);
        for (size_t k = 0; k < order.size(); ++k) {
            int idx       = order[k];
            int val       = sortedPairs[idx].second;
            int winnerVal = sortedPairs[idx].first;
 
            int bound = static_cast<int>(
                std::lower_bound(resultChain.begin(), resultChain.end(), winnerVal) - resultChain.begin()
            ) + 1;
 
            insertVectorBinary(resultChain, val, bound);
        }
    }

    if (hasStraggler)
        insertVectorBinary(resultChain, leftover, static_cast<int>(resultChain.size()));

    seq = resultChain;
}


void PmergeMe::fordJohnsonD(std::deque<int> &seq) {
    int n = static_cast<int>(seq.size());
    if (n <= 1)
        return;

    bool hasStraggler = (n % 2 != 0);
    int  leftover    = hasStraggler ? seq[n - 1] : 0;
 
    std::deque<std::pair<int,int> > nbpairs;
    int pairLimit = n - (hasStraggler ? 1 : 0);
    for (int i = 0; i + 1 < pairLimit; i += 2) {
        if (seq[i] >= seq[i + 1])
            nbpairs.push_back(std::make_pair(seq[i], seq[i + 1]));
        else
            nbpairs.push_back(std::make_pair(seq[i + 1], seq[i]));
    }
 
    std::deque<int> mainChain;
    for (std::deque<std::pair<int, int> >::iterator it = nbpairs.begin();
        it != nbpairs.end();
        ++it)
    {
        mainChain.push_back(it->first);
    }

    fordJohnsonD(mainChain);

    std::deque<std::pair<int,int> > sortedPairs;
    std::deque<std::pair<int,int> > unsortedPairs = nbpairs;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < unsortedPairs.size(); ++j) {
            if (unsortedPairs[j].first == mainChain[i]) {
                sortedPairs.push_back(unsortedPairs[j]);
                unsortedPairs.erase(unsortedPairs.begin() + j);
                break;
            }
        }
    }

    std::deque<int> resultChain;
    resultChain.push_back(sortedPairs[0].second);
    for (size_t i = 0; i < sortedPairs.size(); ++i)
        resultChain.push_back(sortedPairs[i].first);
 
    int pendCount = static_cast<int>(sortedPairs.size()) - 1;
    if (pendCount > 0) {
        std::vector<int> order = getJacobsthalOrder(pendCount);
        for (size_t k = 0; k < order.size(); ++k) {
            int idx       = order[k];
            int val       = sortedPairs[idx].second;
            int winnerVal = sortedPairs[idx].first;
 
            int bound = static_cast<int>(
                std::lower_bound(resultChain.begin(), resultChain.end(), winnerVal) - resultChain.begin()
            ) + 1;
 
            insertDequeBinary(resultChain, val, bound);
        }
    }

    if (hasStraggler)
        insertDequeBinary(resultChain, leftover, static_cast<int>(resultChain.size()));
 
    seq = resultChain;
}


static double elapsedUs(struct timespec &start, struct timespec &end) {
    return (end.tv_sec  - start.tv_sec)  * 1e6
         + (end.tv_nsec - start.tv_nsec) / 1e3;
}

void PmergeMe::executesort() {
    struct timespec t0, t1;

    clock_gettime(CLOCK_MONOTONIC, &t0);
    fordJohnsonV(_vectordata);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    _vectorElapsed = elapsedUs(t0, t1);


    clock_gettime(CLOCK_MONOTONIC, &t0);
    fordJohnsonD(_dequedata);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    _dequeElapsed = elapsedUs(t0, t1);
}

void PmergeMe::printContainer(const std::vector<int>& container, const std::string& label) const {
    std::cout << label << ":";
    for (size_t i = 0; i < container.size(); ++i)
        std::cout << " " << container[i];
    std::cout << "\n";
}

void PmergeMe::printResult() const {
    printContainer(_inputnbs, "Before");
    printContainer(_vectordata, "After");
    std::cout << std::fixed;
    std::cout.precision(5);
    std::cout << "Time to process a range of " << _vectordata.size()
              << " elements with std::vector : " << _vectorElapsed << " us\n";
    std::cout << "Time to process a range of " << _dequedata.size()
              << " elements with std::deque  : " << _dequeElapsed << " us\n";
}