/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:12:49 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/10 11:39:02 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	// std::cout << "Default AMateria constructor called" << std::endl;
	this->type = "undefined";
}

AMateria::~AMateria()
{
	// std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	// std::cout << "Copy AMateria constructor called" << std::endl;
	(void)copy;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
	// std::cout << "AMateria = operator overload called" << std::endl;
	(void)copy;
	return (*this);
}

AMateria::AMateria(std::string const &type)
{
	// std::cout << "Type AMateria constructor called" << std::endl;
	this->type = type;
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* damages " << target.getName() << " *" << std::endl;
}
