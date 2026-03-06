#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP
#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const n,int g);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        std::string const &getName() const;
        int getGrade() const;
        void GradeTooLowException(int grade);
        void GradeTooHighException(int grade);
        void incrementGrade();
        void decrementGrade();
};
std::ostream	&operator<<(std::ostream &o, const Bureaucrat &fixed);


#endif