#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other) : AForm(other), target(other.target)
{
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{
    if (this != &other)
    {
        this->target = other.target;
        AForm::operator=(other);
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getSignd() == false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGrade_exc())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << "* drilling noises *" << std::endl;
        if (rand() % 2)
            std::cout << target << " has been robotomized successfully" << std::endl;
        else
            std::cout << "robotomy failed" << std::endl;
    }
}