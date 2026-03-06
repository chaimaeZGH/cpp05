#include "Bureaucrat.hpp"

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &fixed)
{
    o << fixed.getName()<< ",bureaucrat grade" <<fixed.getGrade() << std::endl;
    return o;
}

void Bureaucrat::GradeTooHighException()
{
    if(this->grade<1)
        throw "too high";
}
void Bureaucrat::GradeTooLowException()
{
    if(this->grade>150)
        throw "too low";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name)
{
    this->grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if(this != &other)
    {
        this->grade=other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(std::string const n,int g): name(n)
{
    grade = g;
    if (grade < 1)
        GradeTooHighException();
    if (grade > 150)
        GradeTooLowException();
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        GradeTooLowException();
    grade++;
}
