#include <iostream>
#include "Array.hpp"

int main()
{
	srand(time(NULL));
	Array<std::string>	test;
	try 
	{
		std::cout << test[1] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<int> testTwo(5);
	try
	{
		std::cout << testTwo[1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		for (size_t i = 0; i < testTwo.size(); i++)
			testTwo[i] = rand();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		for (size_t i = 0; i < testTwo.size(); i++)
			std::cout << testTwo[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
