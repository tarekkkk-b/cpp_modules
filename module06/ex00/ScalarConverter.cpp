#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref)
{
	(void)ref;
	return *this;
}

// convert function
void ScalarConverter::convert(const std::string input)
{
	e_types	type = identifyType(input);
	
	switch (type)
	{
	case CHAR:
		fromChar(input);
		break;

	case INT:
		fromInt(input);
		break;

	case FLOAT:
		fromFloat(input);
		break;

	case DOUBLE:
		fromDouble(input);
		break;

	default:
		std::cerr << "Error: couldn't identify literal type.\n";
		break;
	}
}

ScalarConverter::e_types ScalarConverter::identifyType(const std::string input)
{
	if (isChar(input))
		return CHAR;
	if (isInt(input))
		return INT;
	if (isFloat(input))
		return FLOAT;
	if (isDouble(input))
		return DOUBLE;
	return INVALID;
}

void ScalarConverter::fromChar(const std::string input)
{
	char character = input[0];

	// char
	std::cout << "char: ";
	if (std::isprint(character))
		std::cout << "'" << static_cast<char>(character) << "'\n";
	else
		std::cout << "non displayable\n";

	// int
	std::cout << "int: " << static_cast<int>(character) << "\n";

	// float
	std::cout << "float: " << static_cast<float>(character) << ".0f" << "\n";
	
	// double
	std::cout << "double: " << static_cast<double>(character) << ".0" << "\n";
}

void ScalarConverter::fromInt(const std::string input)
{
	int number;
	std::stringstream ss(input.c_str());
	if (!(ss >> number) || !(ss.eof()))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return ;
	}

	// char
	std::cout << "char: ";
	if (number >= 0 && number <= 127)
	{
		if (isprint(number))
			std::cout << static_cast<char>(number) << "\n";
		else
			std::cout << "non displayable\n";
	}
	else
		std::cout << "impossible\n";

	// int
	std::cout << "int: " << number << "\n";
		
	//float
	std::cout << "float: " << static_cast<float>(number) << ".0f" << "\n";
		
	// double
	std::cout << "double: " << static_cast<double>(number) << ".0" << "\n";
}

int handle_inff(const std::string input)
{
	if (input == "+inff" || input == "-inff" || input == "nanf")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		if (input[0] == '+')
		{
			std::cout << "float: +inff\n";
			std::cout << "double: +inf\n";
		}
		else if (input[0] == '-')
		{
			std::cout << "float: -inff\n";
			std::cout << "double: -inf\n";
		}
		else
		{
			std::cout << "float: nanf\n";
			std::cout << "double: nan\n";
		}
		return 1;
	}
	return 0;
}

void ScalarConverter::fromFloat(const std::string input)
{
	float number;
	std::string toParse = input;
	
	if (handle_inff(input))
	return ;
	
	if (!toParse.empty() && toParse[toParse.length() - 1] == 'f')
	toParse.erase(toParse.length() - 1);	
	
	std::stringstream ss(toParse);
	if (!(ss >> number) || !(ss.eof()))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return ;
	}
	
	// char
	std::cout << "char: ";
	if (static_cast<int>(number) >= 0 && static_cast<int>(number) <= 127)
	{
		if (isprint(static_cast<int>(number)))
		std::cout << static_cast<char>(number) << std::endl;
		else
		std::cout << "non displayable\n";
	}
	else
	std::cout << "impossible\n";
	
	// int
	std::cout << "int: ";
	// if (number > static_cast<int>(INT_MAX) || number < static_cast<int>(INT_MIN))
	int int_num;
	std::stringstream ss_int(input.substr(0, input.find_first_not_of("0123456789")));
	if (!(ss_int >> int_num) || !(ss_int.eof()))
	{
		std::cout << "impossible" << std::endl;
	}
	else
	    std::cout << static_cast<int>(int_num) << std::endl;

	// float
	std::cout << "float: " << number << "f" << std::endl;

	// double
	std::cout << "double: " << static_cast<double>(number) << std::endl;
}

int	handle_inf(const std::string input)
{
	if (input == "+inf" || input == "-inf" || input == "nan")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		if (input[0] == '+')
		{
			std::cout << "float: +inff\n";
			std::cout << "double: +inf\n";
		}
		else if (input[0] == '-')
		{
			std::cout << "float: -inff\n";
			std::cout << "double: -inf\n";
		}
		else
		{
			std::cout << "float: nanf\n";
			std::cout << "double: nan\n";
		}
		return 1;
	}
	return 0;
}

void ScalarConverter::fromDouble(const std::string input)
{
	double number;

	if (handle_inf(input))
		return ;
	
	std::stringstream ss(input);
	if (!(ss >> number) || !(ss.eof()))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return ;
	}

	// char
	std::cout << "char: ";
	if (static_cast<int>(number) >= 0 && static_cast<int>(number) <= 127)
	{
		if (isprint(static_cast<int>(number)))
			std::cout << static_cast<char>(number) << std::endl;
		else
			std::cout << "non displayable\n";
	}
	else
		std::cout << "impossible\n";
	
	// int
	std::cout << "int: ";
	if (number > static_cast<double>(INT_MAX) || number < static_cast<double>(INT_MIN))
	    std::cout << "impossible" << std::endl;
	else
	    std::cout << static_cast<int>(number) << std::endl;

	// float
	std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;

	// double
	std::cout << "double: " << number << std::endl;
}

// identify 
bool isInt(const std::string input)
{
	int i = 0;

	if (input[i] == '-' || input[i] == '+')
		i++;
	if (!input[i])
		return false;
	while (input[i])
	{
		if (!std::isdigit(input[i]))
			return false;
		i++;
	}
	return true;
}

bool isChar(const std::string input)
{
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		return true;
	return false;
}

bool isFloat(const std::string input)
{
	int trigger = 0;
	if (input.empty() || input[input.length() - 1] != 'f')
		return false;
	if (input == "nanf" || input == "+inff" || input == "-inff")
		return true;
	size_t i = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;
	if (i == input.length() - 1)
		return false;
	while (i < input.length() - 1)
	{
		if (input[i] == '.')
		{
			trigger++;
			i++;
			continue;
		}
		if (!isdigit(input[i]))
		return false;
		i++;
	}
	if (trigger > 1)
		return false;
	return true;
}

bool isDouble(const std::string input)
{
	int trigger = 0;
	if (input.empty())
		return false ;
	if (input == "nan" || input == "+inf" || input == "-inf")
		return true;
	if (input[input.length() - 1] == 'f')
		return false;
	size_t i = 0;
	if (input[i] == '-' || input[i] == '+')
	i++;
	if (i == input.length() - 1)
		return false;
	while (i < input.length())
	{
		if (input[i] == '.' && !trigger)
		{
			trigger = 1;
			i++;
			continue;
		}
		if (!isdigit(input[i]))
			return false;
		i++;
	}
	if (!trigger)
		return false;
	return true;
}
