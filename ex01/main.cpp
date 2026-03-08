#include "Form.hpp"

int main()
{
    Bureaucrat brr("bruc1",5);
    std::cout << brr ;
    Form fr("fr1",3,7);
    std::cout << fr ;
    try
    {
        fr.beSigned(brr);
    }
     catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    brr.incrementGrade();
    brr.incrementGrade();
    try
    {
        fr.beSigned(brr);
        std::cout <<"it's signed" << std::endl;
    }
     catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << fr ;
}