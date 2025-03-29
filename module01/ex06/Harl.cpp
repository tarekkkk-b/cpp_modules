/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:30:41 by tabadawi          #+#    #+#             */
/*   Updated: 2024/09/28 20:19:13 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}


void Harl::debug()
{
	std::cout << "[ DEBUG ]\n" "I love having extra bacon for my " << \
	"7XL-double-cheese-triple-pickle-specialketchup burger. " << \
	"I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]\n" "I cannot believe adding extra bacon costs more money. "
	"You didn't put enough bacon in my burger! If you did, "
	"I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\n" "I think I deserve to have some extra bacon for free. " \
	"I've been coming for years whereas you started " \
	"working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]\n" "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int i = 0;
	std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (; i < 4; i++)
	{	
		if (arr[i] == level)
			break ;
	}
	switch (i)
	{
		case 0:
			Harl::debug();
			std::cout << std::endl;
		case 1:
			Harl::info();
			std::cout << std::endl;
		case 2:
			Harl::warning();
			std::cout << std::endl;
		case 3:
			Harl::error();
			break;
		case 4:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}