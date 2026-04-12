#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat& b);
        virtual void execute(const Bureaucrat& executor) const;
        virtual void action() const = 0;
        class GradeTooHighException : public std::exception
        {
        public:
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
        public:
            const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif