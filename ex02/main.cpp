#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat worker("Worker", 70);
        Bureaucrat intern("Intern", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << "\n--- SIGNING FORMS ---\n";
        boss.signForm(shrub);
        boss.signForm(robot);
        boss.signForm(pardon);
        std::cout << "\n--- EXECUTING FORMS ---\n";
        boss.executeForm(shrub);
        boss.executeForm(robot);
        boss.executeForm(pardon);
        std::cout << "\n--- ROBOTOMY MULTIPLE TIMES ---\n";
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
        std::cout << "\n--- LOW GRADE TEST ---\n";
        intern.signForm(robot);
        intern.executeForm(robot);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}