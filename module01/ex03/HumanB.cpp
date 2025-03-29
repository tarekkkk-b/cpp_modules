/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:59:18 by tabadawi          #+#    #+#             */
/*   Updated: 2024/08/30 19:23:21 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = nullptr;
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (this->weapon != nullptr){
		std::cout << this->name << " attacks with their " << this->weapon->getType();
		std::cout << std::endl;
	}
	else
		std::cout << this->name << " No weapon to attack found." << std::endl;
}

void	HumanB::setWeapon(Weapon &type)
{
	this->weapon = &type;
}