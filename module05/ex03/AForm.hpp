#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		const int grade;
		const int exec;
		bool isSigned;
		
	public:
		
		// instantiation
		AForm();
		AForm(const std::string _name, const int _grade, const int _exec);
		AForm &operator=(const AForm &ref);
		AForm(const AForm &copy);
		~AForm();

		// getters
		std::string getName() const;
		int getGrade() const;
		int getExec() const;
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
		class NotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		void check_requirements(Bureaucrat const &executor) const;
		virtual void execute(Bureaucrat const &executor) const = 0;
};

// overload
std::ostream &operator<<(std::ostream &os, const AForm &f);










