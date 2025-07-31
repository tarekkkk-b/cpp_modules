#include "RPN.hpp"


int main(int ac, char **av)
{
	if (ac == 2)
	{
		RPN rpn;
		try
		{
			rpn.parsing(av[1]);
			rpn.calculate();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		return 0;
	}
	else
		std::cerr << "Usage: ./RPN \"EQUATION\"" << std::endl;
	return 1;
}