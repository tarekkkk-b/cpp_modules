#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void)copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref)
{
	(void)ref;
	return *this;
}

const char *BitcoinExchange::CantOpenException::what() const throw()
{
	return "Couldn't open database.\n";
}

const char *BitcoinExchange::InvalidException::what() const throw()
{
	return "Invalid database.\n";
}

void BitcoinExchange::open_db(const char *input)
{
	this->data.open("data.csv", std::ifstream::in);
	if (!this->data.is_open())
	{
		std::cerr << "data.csv: ";
		throw CantOpenException();
	}
	this->user.open(input, std::ifstream::in);
	if (!this->user.is_open())
	{
		std::cerr << input << ": ";
		throw CantOpenException();
	}
	this->fileName = input;
}

void BitcoinExchange::parse_db()
{
	if (!this->validateData())
	{
		std::cerr << "data.csv: ";
		throw InvalidException();
	}
	std::map<std::string, double>::iterator it;
	it = this->db.begin();
	while (it != this->db.end())
	{
		std::ostringstream oss;
		oss << it->second;
		std::string test = oss.str();
		// printf("%f\n", it->second);
		// std::cout << it->first << "," << test << std::endl;
		it++;
	}
}

static bool is_digit(std::string str, int flag)
{
	int i = 0;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return false;
		i++;
	}
	int nbr;
	std::stringstream ss(str);
	if (!(ss >> nbr) || !ss.eof())
		return false;

	switch (flag)
	{
		case 1 :
			if (str.size() == 4)
				if (nbr < 2025)
					return true;
			return false;
		case 2:
			if (str.size() == 2)
				if (nbr < 13 && nbr > 0)
					return true;
			return false;
		case 3:
			if (str.size() == 2)
				if (nbr < 32 && nbr > 0)
					return true;
			return false;
	}
	return true;
}

bool BitcoinExchange::validLine(std::string str, char sep)
{
	std::string date;
	std::string value;

	int checker = 0;
	if (str.find_first_not_of("0123456789,|-. \t") != std::string::npos || str.find_first_of(sep) == std::string::npos)
		return false;
	if (sep == ',')
	{
		date = str.substr(0, str.find_first_of(','));
		value = str.substr(str.find_first_of(',') + 1);
	}
	else if (sep == '|')
	{
		date = str.substr(0, str.find(" | "));
		value = str.substr(str.find(" | ") + 3);
	}
	
	if (date.size() < 10 || date.find_first_of('-') == std::string::npos || date.find_first_of('-') != 4 || date.find_last_of('-') != 7)
		return false;
	if (!is_digit(date.substr(0, 4), 1) || !is_digit(date.substr(5, 2), 2) || !is_digit(date.substr(8, 2), 3))
		return false;
	for (size_t i = 0; i < value.size(); i++)
	{
		if (i == 0 && (value[i] == '-' || value[i] == '+'))
			continue;
		if (value[i] == '.')
		{
			if (i == 0 || i == value.size() - 1)
				return false;
			checker++;
			continue;
		}
		if (checker > 1 )
			return false;
		if (!std::isdigit(value[i]))
			return false;
	}
	return true;
}

bool BitcoinExchange::validateData()
{
	std::string line;

	std::getline(this->data, line);
	if (line != "date,exchange_rate")
	{
		// std::cerr << "here1\n";
		return false;
	}
	while (std::getline(this->data, line))
	{
		if (!this->validLine(line, ','))
		{
			// std::cerr << "here2\n" << line << std::endl;
			return false;
		}
		std::string date = line.substr(0, 10);
		double value = static_cast<double>(std::atof(line.substr(line.find_first_of(',') + 1, std::string::npos).c_str()));
		// if (value < 0 || value > 1000)
		// {
		// 	std::cerr << value << " here3\n";
		// 	return false;
		// }
		this->db.insert(std::make_pair(date, value));
	}
	return true;
}

void BitcoinExchange::printResults()
{
	std::string line;

	std::getline(this->user, line);
	if (line != "date | value")
	{
		std::cerr << this->fileName << ": ";
		throw InvalidException();
	}
	// int i = 0;
	while (std::getline(this->user, line))
	{
		// i++;
		// std::cout << i << std::endl;
		// std::cout << line << ":	";
		if (!this->validLine(line, '|'))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::string year = line.substr(0, 10);
		double value = static_cast<double>(std::atof(line.substr(line.find(" | ") + 3, std::string::npos).c_str()));
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		else if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		MAP::iterator it;
		it = this->db.find(year);
		if (it == this->db.end())
		{
			it = this->db.lower_bound(year);
			// std::cout << it->first << ":    " << it->second << std::endl;
			if (it == this->db.begin())
			{
				std::cerr << "Error: Year and its lower bound doesn't exist" << " => " << line << "\n";
				continue;
			}
			it--;
			// std::cout << year << " => " << value << " = " << it->first << "\n";
		}
		std::cout << year << " => " << value << " = " << it->second * value << "\n";
		
	}
}
