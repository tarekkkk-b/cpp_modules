#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Usage:	./PmergeMe [ARGS]" << std::endl;
		return 1;
	}
	PmergeMe run;
	try
	{
		run.validate(av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
