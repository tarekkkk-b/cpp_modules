#include <stack>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int> nums;
		std::stack<std::string> split;
		RPN(const RPN &copy);
		RPN &operator=(const RPN &ref);
		
	public:
		RPN();
		~RPN();

		void parsing(std::string arg);
		int convert(std::string num);
		void operation(int sign);
		void calculate();

		class InvalidArgument : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class ConversionError : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class InvalidSequence : public std::exception
		{
			public:
				const char *what() const throw();
		};
};