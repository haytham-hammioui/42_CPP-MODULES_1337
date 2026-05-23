#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN
{
    private:
        std::stack<int> s;
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void calculate(const std::string &str);
};