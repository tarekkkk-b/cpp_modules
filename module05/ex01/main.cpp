#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form test("test", 9, 7);
		try
		{
			Bureaucrat tester("tester", 8);
			tester.signForm(test);
		}
		catch (std::exception &f)
		{
			std::cerr << "noob\n";
			std::cerr << f.what() << '\n';
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}