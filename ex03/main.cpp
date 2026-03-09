#include "Intern.hpp"

// int main()
// {
//     Intern someRandomIntern;
//     AForm* rrf;
//     rrf = someRandomIntern.makeForm("robotomy request", "Bender");
// }

#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
    Intern intern;
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    std::string targets[] = {"Garden","Bender", "Arthur"};
    
    for (int i = 0; i < 3; i++) 
    {
        std::cout << "***\nTrying to create: " << formNames[i] << std::endl;
        AForm* form = intern.makeForm(formNames[i], targets[i]);
        
        if (form)
        {
            std::cout << "Success! Created form: " << form->getName() << std::endl;
            std::cout << "  Target: " << targets[i] << std::endl;
            std::cout << "  Grade to sign: " << form->getGrade_sig() << std::endl;
            std::cout << "  Grade to execute: " << form->getGrade_exc() << std::endl;
            delete form;
        } 
        else
            std::cout << "Failed to create form" << std::endl;
    }

    std::cout << "***\nTrying to create invalid form:" << std::endl;
    AForm* invalid = intern.makeForm("invalid form", "test");
    if (!invalid)
        std::cout << "Properly handled invalid form (returned NULL)" << std::endl;
}