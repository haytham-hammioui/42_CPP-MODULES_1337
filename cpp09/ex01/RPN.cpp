#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : s(other.s) {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        s = other.s;
    return *this;
}

RPN::~RPN() {}

static bool isOperator(const std::string &t)
{
    return (t == "+" || t == "-" || t == "*" || t == "/");
}

void RPN::calculate(const std::string &expr)
{
    std::istringstream iss(expr);
    std::string token;

    try
    {
        while (iss >> token)
        {
            if (isOperator(token))
            {
                if (s.size() < 2)
                    throw std::runtime_error("Error");

                int b = s.top(); s.pop();
                int a = s.top(); s.pop();

                if (token == "+")
                    s.push(a + b);
                else if (token == "-")
                    s.push(a - b);
                else if (token == "*")
                    s.push(a * b);
                else if (token == "/")
                {
                    if (b == 0)
                        throw std::runtime_error("Error");
                    s.push(a / b);
                }
            }
            else
            {
                if (token.size() != 1 || !std::isdigit(token[0]))
                    throw std::runtime_error("Error");

                s.push(token[0] - '0');
            }
        }

        if (s.size() != 1)
            throw std::runtime_error("Error");

        std::cout << s.top() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Error" << std::endl;
    }
    while (!s.empty())
        s.pop();
}