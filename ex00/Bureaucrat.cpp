#include "Bureaucrat.hpp"

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &fixed)
{
    o << fixed.getName()<< ",bureaucrat grade" <<fixed.getGrade() << std::endl;
    return o;
}

void Bureaucrat::GradeTooHighException(int grade)
{
    if(grade<1)
        throw "too high";
}
void Bureaucrat::GradeTooLowException(int grade)
{
    if(grade>150)
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
        GradeTooHighException(grade);
    if (grade > 150)
        GradeTooLowException(grade);
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
        GradeTooHighException(this->grade);
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        GradeTooLowException(this->grade);
    grade++;
}
