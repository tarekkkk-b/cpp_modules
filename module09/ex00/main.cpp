#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		BitcoinExchange btc;
		try
		{
			// open databases
			btc.open_db(av[1]);

			// parse them
			btc.parse_db();

			// get results
			btc.printResults();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
			return 1;
		}
		return 0;
	}
	else
		std::cerr << "Usage: ./btc [input file]" << std::endl;
	return 1;
}