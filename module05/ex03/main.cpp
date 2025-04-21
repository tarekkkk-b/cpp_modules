#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern eshan;
		AForm *test = eshan.makeForm("shrubbery creation`", "home");
		// PresidentialPardonForm test("home");
		// std::cout << test;
		try
		{
			Bureaucrat tester("tester", 8);
			tester.signForm(*test);
			tester.executeForm(*test);

	
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