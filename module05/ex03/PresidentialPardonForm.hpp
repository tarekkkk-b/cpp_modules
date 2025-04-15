#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	
	public:
	// instantiation
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string _target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);
		~PresidentialPardonForm();

		void execute(Bureaucrat const & executor) const;
};
