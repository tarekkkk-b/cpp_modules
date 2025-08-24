#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstdlib>

# define MAP std::map <std::string, double>

class BitcoinExchange
{
	private:
		MAP db;
		std::ifstream data;
		std::ifstream user;
		std::string fileName;
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &ref);
		
	public:
		BitcoinExchange();
		~BitcoinExchange();
		void open_db(const char *input);
		void parse_db();
		bool validLine(std::string str, char sep);
		bool validateData();
		void printResults();

		class CantOpenException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class InvalidException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};