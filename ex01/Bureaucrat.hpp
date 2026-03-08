#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP
#include <iostream>
#include <string>
#include "Form.hpp"

class Form;
class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(std::string const n, int g);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    const std::string &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
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
    void signForm(Form& form);
};
std::ostream	&operator<<(std::ostream &o, const Bureaucrat &buro);

#endif