#include "Bureaucrat.hpp"

// constract
Bureaucrat::Bureaucrat(): name("default")
{
}
Bureaucrat::Bureaucrat(std::string const n,int g): name(n)
{
    if (g < 1)
        throw GradeTooHighException();
    if (g > 150)
        throw GradeTooLowException();

    grade = g;
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

// destract
Bureaucrat::~Bureaucrat()
{}

// geters
const std::string& Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

// change value
void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}


// exeption

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

// ostrem
std::ostream	&operator<<(std::ostream &o, const Bureaucrat &fixed)
{
    o << fixed.getName() << ", bureaucrat grade " << fixed.getGrade() << "." << std::endl;
    return o;
}

// function signed
void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (Form::GradeTooLowException& e) 
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    // or
    // catch (std::exception& e) 
    // {  // Also works (base class)
    //     std::cout << "Caught base: " << e.what() << std::endl;
    // }

}