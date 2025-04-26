#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
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
		std::cerr << "Error: couldn't identify literal type.";
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
	(void)input;
	std::cout << "issa charrrrr";
}

void ScalarConverter::fromInt(const std::string input)
{
	(void)input;
	std::cout << "issa intttttttt";
}

void ScalarConverter::fromFloat(const std::string input)
{
	(void)input;
	std::cout << "issa floatttttttt";
}

void ScalarConverter::fromDouble(const std::string input)
{
	(void)input;
	std::cout << "issa doubleeeee";
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

bool isDouble(const std::string input)
{
	int trigger = 0;
	if (input.empty() || input[input.length() - 1] == 'f')
		return false;
	if (input == "nan" || input == "+inf" || input == "-inf")
		return true;
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

// // converters
// void toChar(const std::string input)
// {
// 	int character;
// 	std::cout << "char: ";
// 	if (input.length() == 1 && !(std::isdigit(input[0])))
// 	character = input[0];
// 	else if (isDigits(input))
// 	character = atoi(input.c_str());
// 	else {
// 		std::cout << "impossible";
// 		return ;
// 	}
// 	if (character < 32 || character > 126 || !std::isprint(character))
// 	std::cout << "Non displayable";
// 	else
// 	std::cout << static_cast<char>(character);
// 	std::cout << std::endl;
// }

// // parsing
// int isDigits(const std::string input)
// {
// 	for (size_t i = 0; i < input.length(); i++)
// 	{
// 		if (!i && (input[i] == '-' || input[i] == '+'))
// 		continue;
// 		if (!std::isdigit(input[i]))
// 		return 0;
// 	}
// 	return 1;
// }