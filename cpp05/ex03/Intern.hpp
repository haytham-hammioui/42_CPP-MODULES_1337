#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern{
public:
    Intern();
    Intern(const Intern& other);
    ~Intern();
    Intern& operator=(const Intern& other);

    AForm* makeForm(std::string formName, std::string target);
};

#endif