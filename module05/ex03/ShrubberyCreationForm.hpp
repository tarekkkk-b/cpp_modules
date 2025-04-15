#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;

	public:
		// instantiation
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string _target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ref);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const & executor) const;
	
};
