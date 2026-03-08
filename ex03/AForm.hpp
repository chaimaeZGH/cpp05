#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
    private:
        std::string const name;
        bool signd;
        int const grade_sig;
        int const grade_exc;
    public:
        AForm();
        AForm(std::string const n,int g_s,int g_e);
        ~AForm();
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
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
        virtual void execute(Bureaucrat const & executor) const = 0;
};
std::ostream	&operator<<(std::ostream &o, const AForm &AForm);
#endif

