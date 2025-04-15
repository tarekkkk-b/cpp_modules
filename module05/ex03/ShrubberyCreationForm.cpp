#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = "RandomTarget";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target)  : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = _target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)  : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = copy.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
	this->target = ref.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		check_requirements(executor);
		int height = 10;
		std::string name = this->target + "_shrubbery";
		std::ofstream file;
		file.open(name.c_str());
		if (!file.is_open())
		{
			std::cout << "Couldnt open file: " << name << std::endl;
			return ;
		}
		for (int i = 1; i < height; ++i)
		{
			for (int j = 0; j < height - i; j++)
			{
				file << " ";
			}
			for (int k = 0; k < (2 * i - 1); k++)
			{
				file << "^";
			}
			file << std::endl;
		}
		file.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}