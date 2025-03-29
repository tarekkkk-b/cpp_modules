/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:50:51 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/10 13:03:20 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	// std::cout << "Default MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	// std::cout << "Copy MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (copy.materias[i])
			this->materias[i] = copy.materias[i]->clone();
		else
			this->materias[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	// std::cout << "MateriaSource = operator overload called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i])
		{
			delete this->materias[i];
			this->materias[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (copy.materias[i])
			this->materias[i] = copy.materias[i]->clone();
		else
			this->materias[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i])
		{
			delete this->materias[i];
			this->materias[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
		return ;
	// std::cout << "we have a materia to learn and the type is: " << materia->getType() << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (!this->materias[i])
		{
			this->materias[i] = materia->clone();
			// std::cout << "materia: " << materia->getType() << " was learnt on the (" << i << ")th round" << std::endl;
			delete materia;
			return ;
		}
	}
	delete materia;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	// std::cout << "the type we wanna create is: " << type << std::endl;
	for (int i = 0; i < 4; i++)
	{
		// std::cout << "this is round number " << i << std::endl;
		if (this->materias[i])
		{
			// std::cout << "this is a: " << this->materias[i]->getType() << std::endl;
			if (this->materias[i]->getType() == type)
			{
				// std::cout << "found" << std::endl;
				return (this->materias[i]->clone());
			}
		}
	}
	// std::cout << "we cudnt create nun" << std::endl;
	return NULL;
}
