/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:35:02 by tabadawi          #+#    #+#             */
/*   Updated: 2024/12/25 09:19:21 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	std::string	DefaultClapTrap = "clap";
	this->name = DefaultClapTrap;
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string &name)
{
	std::cout << "Name constructor called" << std::endl;
	this->name = name;
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->name = copy.name;
	this->hitPoint = copy.hitPoint;
	this->energyPoint = copy.energyPoint;
	this->attackDamage = copy.attackDamage;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &copy)
{
	std::cout << "Overload operator called" << std::endl;
	this->name = copy.name;
	this->hitPoint = copy.hitPoint;
	this->energyPoint = copy.energyPoint;
	this->attackDamage = copy.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (!this->hitPoint){
		std::cout << "ClapTrap " << this->name << " is dead :(" << std::endl;
		return ;
	}
	if (this->energyPoint > 0){
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " <<  this->attackDamage << " points of damage!" << std::endl;
		this->energyPoint--;
	}
	else
		std::cout << "You can't attack anymore because you dont have any more Energy Points :(" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > 0){
		this->hitPoint -= amount;	
		std::cout << "ClapTrap " << this->name << " took damage by " << amount << " points :(" << std::endl;
		if (this->hitPoint < 0)
		{
			this->hitPoint = 0;
			std::cout << "ClapTrap " << this->name << " has died :(" << std::endl;
		}		
	}
	else
		std::cout << "Please select valid amount." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hitPoint){
		std::cout << "ClapTrap " << this->name << " is dead :(" << std::endl;
		return ;
	}
	if (amount > 0){
		if (amount > 10)
			amount = 10;
		if (this->energyPoint > 0){
			this->hitPoint += amount;
			if (this->hitPoint > 10)
				this->hitPoint = 10;
			this->energyPoint--;
			std::cout << "ClapTrap " << this->name << " health increased by " << amount << " points!" << std::endl;
		}
		else
			std::cout << "You can't heal anymore because you dont have any more Energy Points :(" << std::endl;
	}
	else
		std::cout << "Please select valid amount." << std::endl;
}
