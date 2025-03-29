/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:50:14 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/10 15:09:48 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character()
{
	// std::cout << "Default Character constructor called" << std::endl;
	this->name = "bot";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character &copy)
{
	// std::cout << "Copy Character constructor called" << std::endl;
	this->name = "bot";
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i])
			this->inventory[i] = copy.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character &Character::operator=(const Character &copy)
{
	// std::cout << "Character = operator overload called" << std::endl;
	for (int i = 0; i < 4; i++)
	{	
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i])
			this->inventory[i] = copy.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	return (*this);
}

Character::Character(std::string name)
{
	// std::cout << "Name Character constructor called" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::~Character()
{
	// std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{	
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	// std::cout << "hello this is a materia of type: " << m->getType() << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m->clone();
			delete m;
			return ;
		}
	}
	delete m;
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
		return ;
	if (this->inventory[idx])
		this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx > 3 || idx < 0)
		return ;
	if (this->inventory[idx])
	{
		// std::cout << "the materia at index " << idx << " is a " << this->inventory[idx]->getType() << std::endl;
		this->inventory[idx]->use(target);
	}
}

AMateria *Character::getAddress(int idx)
{
	if (idx > 3 || idx < 0)
		return NULL;
	return (this->inventory[idx]);
}
