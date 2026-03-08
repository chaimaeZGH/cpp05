#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other) : AForm(other), target(other.target)
{
    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
    if (this != &other)
    {
        this->target = other.target;
        AForm::operator=(other);
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getSignd() < executor.getGrade())
        throw AForm::GradeTooLowException();
    else if (this->getSignd() == false)
        throw "Form not signed";
    else
        std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}