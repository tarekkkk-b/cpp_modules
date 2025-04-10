#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		const int grade;
		const int exec;
		bool isSigned;
		Form();
		
	public:
		
		// instantiation
		Form(const std::string _name, const int _grade, const int _exec);
		Form &operator=(const Form &ref);
		Form(const Form &copy);
		~Form();

		// getters
		const std::string getName() const;
		const int getGrade() const;
		const int getExec() const;
		bool getIsSigned() const;

		// signing
		void beSigned(const Bureaucrat &ref);

		// exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

// overload
std::ostream &operator<<(std::ostream &os, const Form &f);










