/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:36:16 by tabadawi          #+#    #+#             */
/*   Updated: 2024/12/25 09:43:58 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default Constructor Called" << std::endl;
	this->name = "ScavTrap";
	this->attackDamage = 20;
	this->hitPoint = 100;
	this->energyPoint = 50;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Name Constructor Called" << std::endl;
	this->name = name;
	this->attackDamage = 20;
	this->hitPoint = 100;
	this->energyPoint = 50;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap Copy Constructor Called" << std::endl;
	this->name = copy.name;
	this->attackDamage = copy.attackDamage;
	this->energyPoint = copy.energyPoint;
	this->hitPoint = copy.hitPoint;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &copy)
{
	std::cout << "ScavTrap overload operator Called" << std::endl;
	this->name = copy.name;
	this->attackDamage = copy.attackDamage;
	this->energyPoint = copy.energyPoint;
	this->hitPoint = copy.hitPoint;
	return (*this);
}

void ScavTrap::attack(const std::string	&target)
{
	if (!this->hitPoint){
		std::cout << "ScavTrap " << this->name << " is dead :(" << std::endl;
		return ;
	}
	if (this->energyPoint > 0){
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " <<  this->attackDamage << " points of damage!" << std::endl;
		this->energyPoint--;
	}
	else
		std::cout << "You can't attack anymore because you dont have any more Energy Points :(" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is currently in Guard mode." << std::endl;
}
