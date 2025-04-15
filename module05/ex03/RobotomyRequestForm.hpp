#pragma once
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{

	private:
		std::string target;

	public:
		// instantiation
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string _target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &ref);
		~RobotomyRequestForm();

		void execute(Bureaucrat const & executor) const;
};