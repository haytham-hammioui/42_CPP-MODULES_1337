#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "----- VALID CASE -----" << std::endl;
    try
    {
        Bureaucrat a("Alice", 50);
        Form f("FormA", 60, 30);

        std::cout << a << std::endl;
        std::cout << f << std::endl;

        a.signForm(f);

        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n----- FAIL SIGN (grade too low) -----" << std::endl;
    try
    {
        Bureaucrat b("Bob", 100);
        Form f2("FormB", 50, 30);

        std::cout << b << std::endl;
        std::cout << f2 << std::endl;

        b.signForm(f2);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n----- INVALID FORM (too high grade) -----" << std::endl;
    try
    {
        Form badForm("BadForm1", 0, 10);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n----- INVALID FORM (too low grade) -----" << std::endl;
    try
    {
        Form badForm2("BadForm2", 10, 200);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "\n----- MULTIPLE SIGN TEST -----" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        Form f3("TopSecret", 10, 5);

        intern.signForm(f3); // fail
        boss.signForm(f3);   // success
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "\n----- DOUBLE SIGN TEST -----" << std::endl;
    try{
        Bureaucrat boss("Boss", 1);
        Form f("Secret", 10, 5);

        boss.signForm(f);
        boss.signForm(f);
    }
    catch (std::logic_error &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}