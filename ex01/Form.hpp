#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    private:
        std::string const name;
        bool signd;
        int const grade_sig;
        int const grade_exc;
    public:
        Form();
        Form(std::string const n,int g_s,int g_e);
        ~Form();
        Form(const Form &other);
        Form &operator=(const Form &other);
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        void beSigned(Bureaucrat& br);
        int getGrade_sig() const;
        int getGrade_exc() const;
        bool getSignd() const;
        std::string const &getName() const;
};
std::ostream	&operator<<(std::ostream &o, const Form &form);
#endif




