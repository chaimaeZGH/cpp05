#include "Form.hpp"

Form::Form():name("default"),grade_sig(1),grade_exc(1)
{
    signd = false;
}

Form::Form(std::string const n,int g_s,int g_e):name(n),grade_sig(g_s),grade_exc(g_e)
{
    if (grade_exc < 1 || grade_sig<1)
        throw GradeTooHighException();
    if (grade_exc > 150||grade_sig > 150)
        throw GradeTooLowException();
    signd = false;
}
Form::~Form()
{

}

Form::Form(const Form &other):name(other.name),grade_sig(other.grade_sig),grade_exc(other.grade_exc)
{
    signd = other.signd;
}
Form& Form::operator=(const Form &other)
{
    if(this != &other)
        signd=other.signd;
    return *this;
}

void Form::beSigned(Bureaucrat& br)
{
    if(br.getGrade()>this->grade_sig)
        throw GradeTooLowException();
    this->signd = true;
}

int Form::getGrade_sig() const
{
    return grade_sig;
}
int Form::getGrade_exc() const
{
    return grade_exc;
}
bool Form::getSignd() const
{
    return signd;
}
std::string const& Form::getName() const
{
    return name;
}

std::ostream	&operator<<(std::ostream &o, const Form &buro)
{
    if(buro.getSignd())
        o << "form name : "<< buro.getName()<<" grade required  to sign : " <<buro.getGrade_sig() <<" and grade required to execute : " <<buro.getGrade_exc()<<" is signed" << std::endl;
    else
        o << "form name : "<<buro.getName()<<" grade required  to sign : " <<buro.getGrade_sig() <<" and grade required to execute : " <<buro.getGrade_exc()<<" is not signed" << std::endl;

    return o;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "one or both of the grades are too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "one or both of the grades are too low";
}