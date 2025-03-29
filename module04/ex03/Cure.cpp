/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:28:26 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/10 15:09:37 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria ("cure")
{
	// std::cout << "Default Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria("cure")
{
	// std::cout << "Copy Cure constructor called" << std::endl;
	(void)copy;
}

Cure &Cure::operator=(const Cure &copy)
{
	// std::cout << "Cure = operator overload called" << std::endl;
	(void)copy;
	return (*this);
}

Cure::~Cure()
{
	// std::cout << "Cure destructor called" << std::endl;
}

std::string const &Cure::getType() const
{
	return (this->type);
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
