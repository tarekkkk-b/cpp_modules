#include "AForm.hpp"

AForm::AForm() : name("form"), grade(1), exec(1)
{
}

AForm::AForm(const std::string _name, const int _grade, const int _exec) : name(_name), grade(_grade), exec(_exec)
{
	this->isSigned = false;
	if (_grade < 1 || _exec < 1)
		throw GradeTooHighException();
	if (_grade > 150 || _exec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : name(copy.name), grade(copy.grade) , exec(copy.exec)
{
	this->isSigned = false;
}

AForm &AForm::operator=(const AForm &ref)
{
	(void)ref;
	return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return this->name;
}

int AForm::getGrade() const
{
	return this->grade;
}

int AForm::getExec() const
{
	return this->exec;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

void AForm::beSigned(const Bureaucrat &ref)
{
	if (this->isSigned){
		std::cout << "This AForm is already signed.\n";
		return ;
	}
	if (ref.getGrade() <= this->grade)
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::check_requirements(Bureaucrat const &executor) const
{
	if (!this->isSigned)
		throw NotSignedException();
	if (this->exec < executor.getGrade())
		throw GradeTooLowException();
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "Form \"" << f.getName() << "\" needs at least grade " << f.getGrade() << " to be signed and at least grade " << f.getExec() << " to execute.\n";
	if (f.getIsSigned())
		os << "This form has already been signed\n";
	else
		os << "This form is not yet signed\n";
	return os;
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("This form is not signed.");
}
