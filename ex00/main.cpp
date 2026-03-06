#include "Bureaucrat.hpp"
int main()
{
    try
    {
        Bureaucrat brr("ss",5);
    }
    catch(const char *txt)
    {
        std::cout << txt<< std::endl;
    }
    
}
