/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 22:01:04 by tabadawi          #+#    #+#             */
/*   Updated: 2024/09/28 15:39:12 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	open_files(std::ifstream &file, std::ofstream &replace, std::string name)
{
	file.open(name.c_str());
	if (!file.is_open())
	{
		std::cout << "Couldnt open file: " << name << std::endl;
		return (0);
	}
	replace.open((name + ".replace").c_str(), std::ios::trunc);
	if (!replace.is_open())
	{
		std::cout << "Couldnt open file: " << name + ".replace" << std::endl;
		file.close();
		return (0);
	}
	return (1);
}

void	write_file(std::ifstream &file, std::ofstream &replace, int len, std::string s1, std::string s2)
{
	std::string	str;
	std::size_t finder;
	while (std::getline(file, str))
	{
		finder = str.find(s1);
		int i = 0;
		while (finder != std::string::npos)
		{
			while (i < (int)finder)
				replace << str[i++];
			replace << s2;
			finder = str.find(s1, finder + 1);
			i += len;
		}
		replace << str.substr(i, std::string::npos) << std::endl;
	}
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "wrong number of arguments\n";
		return (1);
	}
	std::string		name = std::string(av[1]);
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::ifstream	file;
	std::ofstream	replace;
	if (!open_files(file, replace, name))
		return (1);
	write_file(file, replace, s1.size(), s1, s2);
	file.close();
	replace.close();
	return (0);
}
