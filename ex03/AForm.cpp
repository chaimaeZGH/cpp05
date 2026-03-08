#include "AForm.hpp"

AForm::AForm():name("default"),grade_sig(1),grade_exc(1)
{
    signd = false;
}

AForm::AForm(std::string const n,int g_s,int g_e):name(n),grade_sig(g_s),grade_exc(g_e)
{
    if (grade_exc < 1 || grade_sig<1)
        throw GradeTooHighException();
    if (grade_exc > 150||grade_sig > 150)
        throw GradeTooLowException();
    signd = false;
}
AForm::~AForm()
{

}

AForm::AForm(const AForm &other):name(other.name),grade_sig(other.grade_sig),grade_exc(other.grade_exc)
{
    signd = other.signd;
}
AForm& AForm::operator=(const AForm &other)
{
    if(this != &other)
        signd=other.signd;
    return *this;
}

void AForm::beSigned(Bureaucrat& br)
{
    if(br.getGrade()>this->grade_sig)
        throw GradeTooLowException();
    this->signd = true;
}

int AForm::getGrade_sig() const
{
    return grade_sig;
}
int AForm::getGrade_exc() const
{
    return grade_exc;
}
bool AForm::getSignd() const
{
    return signd;
}
std::string const& AForm::getName() const
{
    return name;
}

std::ostream	&operator<<(std::ostream &o, const AForm &buro)
{
    if(buro.getSignd())
        o << "AForm name : "<< buro.getName()<<" grade required  to sign : " <<buro.getGrade_sig() <<" and grade required to execute : " <<buro.getGrade_exc()<<" is signed" << std::endl;
    else
        o << "AForm name : "<<buro.getName()<<" grade required  to sign : " <<buro.getGrade_sig() <<" and grade required to execute : " <<buro.getGrade_exc()<<" is not signed" << std::endl;

    return o;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "one or both of the grades are too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "one or both of the grades are too low";
}