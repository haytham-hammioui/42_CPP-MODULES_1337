#include "Bureaucrat.hpp"

int main()
{
    std::cout << "---- VALID CREATION ----" << std::endl;
    try
    {
        Bureaucrat a("Alice", 50);
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---- INVALID CREATION ----" << std::endl;
    try
    {
        Bureaucrat x("ErrorHigh", 0);
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat y("ErrorLow", 151);
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---- INCREMENT TEST ----" << std::endl;
    try
    {
        Bureaucrat d("David", 2);
        std::cout << d << std::endl;

        d.incrementGrade();
        std::cout << "After increment: " << d << std::endl;

        d.incrementGrade();
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---- DECREMENT TEST ----" << std::endl;
    try
    {
        Bureaucrat e("Eve", 149);
        std::cout << e << std::endl;

        e.decrementGrade();
        std::cout << "After decrement: " << e << std::endl;

        e.decrementGrade();
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}