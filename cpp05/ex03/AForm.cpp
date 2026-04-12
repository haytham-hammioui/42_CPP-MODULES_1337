#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (isSigned)
        throw std::logic_error("Form is already signed!");
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
    if (!isSigned)
        throw std::logic_error("Form is not signed!");
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
    action();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << f.getName()
       << ", signed: " << f.getIsSigned()
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}

