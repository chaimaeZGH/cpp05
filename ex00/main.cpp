#include "Bureaucrat.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 2);
        std::cout << a ;
        a.incrementGrade();
        std::cout << "After increment: " << a ;
        a.incrementGrade(); // should throw (grade would become 0)
    }
   catch (Bureaucrat::GradeTooHighException& e) {  // Catch TYPE 1
        std::cout << "High: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {   // Catch TYPE 2
        std::cout << "Low: " << e.what() << std::endl;  // ← This one runs
    }

    std::cout << "---------------------" << std::endl;

    try
    {
        Bureaucrat b("Bob", 150);
        std::cout << b ;

        b.decrementGrade(); // should throw
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {  // Catch TYPE 1
        std::cout << "High: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {   // Catch TYPE 2
        std::cout << "Low: " << e.what() << std::endl;  // ← This one runs
    }
    // ther is this type of throw that throw type exeption wish is the parent class of both low and high exeptions
    // catch(const std::exception &e)
    // {
    //     std::cout << "Exception: " << e.what() << std::endl;
    // }
    std::cout << "---------------------" << std::endl;

    try
    {
        Bureaucrat c("Charlie", 0); // should throw in constructor
        std::cout << c ;
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {  // Catch TYPE 1
        std::cout << "High: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {   // Catch TYPE 2
        std::cout << "Low: " << e.what() << std::endl;  // ← This one runs
    }
    
    return 0;
}