#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	RobotomyRequestForm rbf = RobotomyRequestForm("Tarek");
	try
	{
		PresidentialPardonForm test("home");
		ShrubberyCreationForm test2("home");
		// std::cout << test;
		try
		{
			Bureaucrat tester("tester", 8);
			tester.signForm(rbf);
			tester.executeForm(rbf);
			tester.signForm(test2);
			tester.executeForm(test2);
			tester.signForm(test);
			tester.executeForm(test);
	
			// std::cout << test;
		}
		catch (std::exception &f)
		{
			std::cerr << f.what() << '\n';
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}