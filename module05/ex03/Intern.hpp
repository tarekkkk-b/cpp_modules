#pragma once
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &ref);
		~Intern();

		AForm *makePresidentialForm(const std::string _target);
		AForm *makeRobotomyForm(const std::string _target);
		AForm *makeShrubberyForm(const std::string _target);

		AForm *makeForm(std::string _name, std::string _target);
};