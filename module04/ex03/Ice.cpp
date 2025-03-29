/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:28:30 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/10 15:09:40 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria ("ice")
{
	// std::cout << "Default Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria("ice")
{
	// std::cout << "Copy Ice constructor called" << std::endl;
	(void)copy;
}

Ice &Ice::operator=(const Ice &copy)
{
	// std::cout << "Ice = operator overload called" << std::endl;
	(void)copy;
	return (*this);
}

Ice::~Ice()
{
	// std::cout << "Ice destructor called" << std::endl;
}

std::string const &Ice::getType() const
{
	return (this->type);
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
