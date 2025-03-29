/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:55:42 by tabadawi          #+#    #+#             */
/*   Updated: 2024/12/25 09:43:58 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default Constructor Called" << std::endl;
	this->attackDamage = 30;
	this->hitPoint = 100;
	this->energyPoint = 100;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor Called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Name Constructor Called" << std::endl;
	this->attackDamage = 30;
	this->hitPoint = 100;
	this->energyPoint = 100;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor Called" << std::endl;
	this->attackDamage = copy.attackDamage;
	this->energyPoint = copy.energyPoint;
	this->hitPoint = copy.hitPoint;
}

FragTrap &FragTrap::operator = (const FragTrap &copy)
{
	std::cout << "FragTrap overload operator Called" << std::endl;
	this->name = copy.name;
	this->attackDamage = copy.attackDamage;
	this->energyPoint = copy.energyPoint;
	this->hitPoint = copy.hitPoint;
	return (*this);
}

void FragTrap::attack(const std::string	&target)
{
	if (!this->hitPoint){
		std::cout << "FragTrap " << this->name << " is dead :(" << std::endl;
		return ;
	}
	if (this->energyPoint > 0){
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " <<  this->attackDamage << " points of damage!" << std::endl;
		this->energyPoint--;
	}
	else
		std::cout << "You can't attack anymore because you dont have any more Energy Points :(" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name << " is asking for high fives!!" << std::endl;
}