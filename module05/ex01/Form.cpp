#include "Form.hpp"

Form::Form(const std::string _name, const int _grade, const int _exec) : name(_name), grade(_grade), exec(_exec)
{
	this->isSigned = false;
	if (_grade < 1 || _exec < 1)
		throw GradeTooHighException();
	if (_grade > 150 || _exec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy) : name(copy.name), grade(copy.grade) , exec(copy.exec)
{
	this->isSigned = false;
}

Form &Form::operator=(const Form &ref)
{
	(void)ref;
	return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return (this->name);
}

int Form::getGrade() const
{
	return (this->grade);
}

int Form::getExec() const
{
	return this->exec;
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

void Form::beSigned(const Bureaucrat &ref)
{
	if (this->isSigned){
		std::cout << "This Form is already signed.\n";
		return ;
	}
	if (ref.getGrade() <= this->grade)
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form \"" << f.getName() << "\" needs at least grade " << f.getGrade() << " to be signed and at least grade " << f.getExec() << " to execute.\n";
	if (f.getIsSigned())
		os << "This form has already been signed\n";
	else
		os << "This form is not yet signed\n";
	return os;
}
