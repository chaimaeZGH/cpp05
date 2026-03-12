#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other) : AForm(other), target(other.target)
{
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
    if (this != &other)
    {
        this->target = other.target;
        AForm::operator=(other);
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getSignd() == false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGrade_exc())
        throw AForm::GradeTooLowException();
    else
    {
        std::string filename = this->target + "_shrubbery";
        std::ofstream File1(filename.c_str());

        if (!File1.is_open())
        {
            std::cerr << "Error: Could not create file" << std::endl;
            return;
        }
        File1 << "   *" << std::endl;
        File1 << "  ***" << std::endl;
        File1 << " *****" << std::endl;
        File1 << "*******" << std::endl;
        File1 << "   ||  " << std::endl;
        File1 << "   ||  " << std::endl;
        File1.close();
    }
}