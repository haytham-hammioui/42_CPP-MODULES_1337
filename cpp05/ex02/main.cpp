#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));

    std::cout << "===== BASIC SUCCESS TEST =====" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Marvin");

        boss.signForm(shrub);
        boss.executeForm(shrub);

        boss.signForm(robot);
        boss.executeForm(robot);

        boss.signForm(pardon);
        boss.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== EXECUTE WITHOUT SIGN =====" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub("garden");

        boss.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== LOW GRADE EXECUTION =====" << std::endl;
    try
    {
        Bureaucrat low("Intern", 150);
        ShrubberyCreationForm shrub("park");

        low.signForm(shrub);
        low.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== LOW GRADE SIGN =====" << std::endl;
    try
    {
        Bureaucrat low("Intern", 150);
        PresidentialPardonForm pardon("Target");

        low.signForm(pardon);
        
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== ROBOTOMY RANDOM TEST =====" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robot("RandomGuy");

        boss.signForm(robot);

        for (int i = 0; i < 5; i++)
        {
            boss.executeForm(robot);
            
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== MULTIPLE FORMS =====" << std::endl;
    try
    {
        Bureaucrat mid("Manager", 50);

        ShrubberyCreationForm s("tree");
        RobotomyRequestForm r("robot");
        PresidentialPardonForm p("criminal");

        mid.signForm(s);
        mid.executeForm(s);

        mid.signForm(r);
        mid.executeForm(r);

        mid.signForm(p);
        mid.executeForm(p);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}