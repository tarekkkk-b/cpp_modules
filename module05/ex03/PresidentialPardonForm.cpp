#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = "RandomTarget";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string _target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = _target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = copy.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	this->target = ref.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		check_requirements(executor);
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox.\n";

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
