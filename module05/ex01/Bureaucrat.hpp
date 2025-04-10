#pragma once
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string name;
		int	grade;
		Bureaucrat();

	public:

		// instantiation
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		// getters
		std::string getName() const;
		int	getGrade() const;

		// increment and decrement
		void incrementGrade();
		void decrementGrade();

		// form
		void signForm(Form &form);

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
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);