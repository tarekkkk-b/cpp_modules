#pragma once
#include <iostream>
#include <sstream>
#include <limits.h>
#include <math.h>


class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		enum e_types
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			INVALID
		};
		static e_types identifyType(const std::string input);
		static void fromChar(const std::string input);
		static void fromInt(const std::string input);
		static void fromFloat(const std::string input);
		static void fromDouble(const std::string input);

	public:
		static void convert(const std::string input);

};


// void toChar(const std::string input);
// void toInt(const std::string input);
// void toFloat(const std::string input);
// void toDouble(const std::string input);

bool isInt(const std::string input);
bool isChar(const std::string input);
bool isFloat(const std::string input);
bool isDouble(const std::string input);

// int isDigits(const std::string input);