#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &copy)
{
    if (this == &copy)
        return (*this);
    return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i = 0;
    for (; i < 3; i++)
    {
        if (formName == forms[i])
            break;
    }
    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << formName << std::endl;
        return (new ShrubberyCreationForm(target));
    case 1:
        std::cout << "Intern creates " << formName << std::endl;
        return (new RobotomyRequestForm(target));
    case 2:
        std::cout << "Intern creates " << formName << std::endl;
        return (new PresidentialPardonForm(target));
    default:
        std::cout << "Intern cannot create " << formName << " form" << std::endl;
        return (NULL);
    }
}
    