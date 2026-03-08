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
    catch(const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    try
    {
        Bureaucrat b("Bob", 150);
        std::cout << b ;

        b.decrementGrade(); // should throw
    }
    catch(const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    try
    {
        Bureaucrat c("Charlie", 0); // should throw in constructor
        std::cout << c ;
    }
    catch(const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}