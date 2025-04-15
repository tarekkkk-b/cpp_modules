#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = "RandomTarget";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string _target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = _target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = copy.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
	this->target = ref.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		check_requirements(executor);
		std::cout << "* some drilling noises *\n";
		int random = rand() % 101;
		if (random % 2 == 0)
			std::cout << this->target << " has been robotomized successfully.\n";
		else
			std::cout << this->target << " was unable to be robotomized.\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
