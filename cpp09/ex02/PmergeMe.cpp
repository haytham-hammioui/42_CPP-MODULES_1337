#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

static int toPositiveInt(const std::string& s)
{
    if (s.empty())
        throw std::runtime_error("Error");

    for (size_t i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
            throw std::runtime_error("Error");
    }

    long long val = 0;
    std::stringstream ss(s);
    ss >> val;

    if (val <= 0 || val > 2147483647)
        throw std::runtime_error("Error");

    return static_cast<int>(val);
}

void PmergeMe::parseInput(char **av)
{
    for (int i = 1; av[i]; i++)
    {
        std::string token(av[i]);

        std::stringstream ss(token);
        std::string part;

        while (ss >> part)
        {
            int value = toPositiveInt(part);

            _vec.push_back(value);
            _deq.push_back(value);
        }
    }
}

static std::vector<int> mergeVec(const std::vector<int>& a, const std::vector<int>& b)
{
    std::vector<int> res;
    size_t i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
            res.push_back(a[i++]);
        else
            res.push_back(b[j++]);
    }

    while (i < a.size())
        res.push_back(a[i++]);
    while (j < b.size())
        res.push_back(b[j++]);

    return res;
}

static std::vector<int> mergeInsertSortVec(std::vector<int> arr)
{
    if (arr.size() <= 16)
    {
        std::sort(arr.begin(), arr.end());
        return arr;
    }

    size_t mid = arr.size() / 2;

    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    left = mergeInsertSortVec(left);
    right = mergeInsertSortVec(right);

    return mergeVec(left, right);
}

static std::deque<int> mergeDeq(const std::deque<int>& a, const std::deque<int>& b)
{
    std::deque<int> res;
    size_t i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
            res.push_back(a[i++]);
        else
            res.push_back(b[j++]);
    }

    while (i < a.size())
        res.push_back(a[i++]);
    while (j < b.size())
        res.push_back(b[j++]);

    return res;
}

static std::deque<int> mergeInsertSortDeq(std::deque<int> arr)
{
    if (arr.size() <= 16)
    {
        std::sort(arr.begin(), arr.end());
        return arr;
    }

    size_t mid = arr.size() / 2;

    std::deque<int> left;
    std::deque<int> right;

    for (size_t i = 0; i < mid; i++)
        left.push_back(arr[i]);
    for (size_t i = mid; i < arr.size(); i++)
        right.push_back(arr[i]);

    left = mergeInsertSortDeq(left);
    right = mergeInsertSortDeq(right);

    return mergeDeq(left, right);
}

void PmergeMe::sortVector()
{
    _vec = mergeInsertSortVec(_vec);
}

void PmergeMe::sortDeque()
{
    _deq = mergeInsertSortDeq(_deq);
}

void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;
}

size_t PmergeMe::getSize() const
{
    return _vec.size();
}