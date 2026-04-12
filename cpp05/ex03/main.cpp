#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Intern someRandomIntern;

    AForm* f1 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* f2 = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Marvin");

    Bureaucrat boss("Boss", 1);

    if (f1)
    {
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
    }

    if (f2)
    {
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;
    }

    if (f3)
    {
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete f3;
    }

    AForm* f4 = someRandomIntern.makeForm("unknown form", "???");
    if (f4)
        delete f4;
    return 0;
}