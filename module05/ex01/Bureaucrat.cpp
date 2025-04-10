#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string _name, const int _grade)
{
	this->name = _name;
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	this->grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	this->name = copy.name;
	this->grade = copy.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	this->name = src.name;
	this->grade = src.grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	this->grade--;
	if (this->grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	this->grade++;
	if (this->grade > 150)
		throw GradeTooHighException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << this->name << " couldn't sign " << form.getName() << " because grade is too low" << std::endl;
	}
}
