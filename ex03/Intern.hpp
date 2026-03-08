#ifndef INTERN_HPP
#define INTERM_HPP

class Intern
{
    Intern();
    Intern(const Intern &copy);
    ~Intern();
    Intern &operator=(const Intern &copy);
    AForm *makeForm(std::string formName, std::string target);

}

#endif