#include "easyfind.hpp"
#include <vector>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	try
	{
		std::vector<int> trial;
		for (int i = 0; i < 20; i++)
			trial.push_back(i);
		easyfind(trial, 6);
		std::cout << "number was found\n";

	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
