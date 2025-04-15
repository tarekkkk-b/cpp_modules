#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern &Intern::operator=(const Intern &ref)
{
	(void)ref;
	return (*this);
}

AForm *Intern::makePresidentialForm(const std::string _target)
{
	return (new PresidentialPardonForm(_target));
}

AForm *Intern::makeRobotomyForm(const std::string _target)
{
	return (new RobotomyRequestForm(_target));
}

AForm *Intern::makeShrubberyForm(const std::string _target)
{
	return (new ShrubberyCreationForm(_target));
}


Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string _name, std::string _target)
{
	std::string arr[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm *(Intern::*forms[3])(std::string) = {&Intern::makePresidentialForm, &Intern::makeRobotomyForm, &Intern::makeShrubberyForm};
	for (int i = 0; i < 3; i++)
	{
		if (arr[i] == _name)
			return ((this->*forms[i])(_target));
	}
	std::cerr << "Couldnt't create form \"" << _name << "\" because it doesn't exist.\n";
	return NULL;
}
