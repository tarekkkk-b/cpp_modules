#pragma once
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string name;
		int	grade;

	public:

		// instantiation
		Bureaucrat();
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
		void signForm(AForm &form);
		void executeForm(AForm const & form);

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