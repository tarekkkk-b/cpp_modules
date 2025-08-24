#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

void RPN::parsing(std::string arg)
{
	if (arg.find_first_of("0123456789+-*/") == std::string::npos)
		throw InvalidArgument();
	if (arg.find_first_not_of("0123456789+-*/ \t") != std::string::npos)
		throw InvalidArgument();
	
	std::stringstream ss(arg);
	std::stack<std::string> temp;
	std::string word;

	while (ss >> word)
	{
		if (word.size() != 1)
			throw InvalidArgument();
		temp.push(word);
	}

	while (!temp.empty())
	{
		this->split.push(temp.top());
		temp.pop();
	}
}

int RPN::convert(std::string num)
{
	std::stringstream ss(num);
	int nbr;
	
	if (!(ss >> nbr) || !(ss.eof()))
		throw ConversionError();
	return nbr;
}

void RPN::operation(int sign)
{
	int num2 = this->nums.top();
	this->nums.pop();
	int num1 = this->nums.top();
	this->nums.pop();
	int res;

	switch (sign)
	{
		case 1:
			res = num1 + num2;
			break;
		case 2:
			res = num1 - num2;
			break;
		case 3:
			res = num1 * num2;
			break;
		case 4:
			res = num1 / num2;
			break;
	}
	this->nums.push(res);
}

static int oper_check(std::string oper)
{
	if (oper == "+")
		return 1; 
	if (oper == "-")
		return 2; 
	if (oper == "*")
		return 3; 
	if (oper == "/")
		return 4;
	return 0;
}

void RPN::calculate()
{
	while (!this->split.empty())
	{
		int check = oper_check(this->split.top());
		switch (check)
		{
			case 0:
				this->nums.push(convert(this->split.top()));
				this->split.pop();
				break;
			case 1:
				if (this->nums.size() < 2)
					throw InvalidSequence();
				this->operation(1);
				this->split.pop();
				break;
			case 2:
				if (this->nums.size() < 2)
					throw InvalidSequence();
				this->operation(2);
				this->split.pop();
				break;
			case 3:
				if (this->nums.size() < 2)
					throw InvalidSequence();
				this->operation(3);
				this->split.pop();
				break;
			case 4:
				if (this->nums.size() < 2)
					throw InvalidSequence();
				this->operation(4);
				this->split.pop();
				break;
		}
	}
	if (this->nums.size() > 1)
		throw InvalidSequence();
	std::cout << this->nums.top() << std::endl;
}

const char *RPN::InvalidArgument::what() const throw()
{
	return "Invalid argument provided.";
}

const char *RPN::ConversionError::what() const throw()
{
	return "Conversion system error.";
}

const char *RPN::InvalidSequence::what() const throw()
{
	return "Invalid sequence of numbers and operators.";
}