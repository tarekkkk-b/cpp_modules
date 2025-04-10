#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat bob("Bob", 9);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat alice("Alice", 1);
		alice.incrementGrade();
		Bureaucrat alex("alex", 7);
		std::cout << alex << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}