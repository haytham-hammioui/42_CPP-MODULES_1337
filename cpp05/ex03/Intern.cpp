#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

static AForm* createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string Names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm* (*Forms[3])(std::string) = {
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };

    for (int i = 0; i < 3; i++) {
        if (Names[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return Forms[i](target);
        }
    }
    std::cout << "Intern couldn't create " << formName << std::endl;
    return NULL;
}