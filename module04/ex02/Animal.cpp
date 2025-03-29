/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:43:37 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/02 20:40:35 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

abstractAnimal::abstractAnimal()
{
	std::cout << "abstractAnimal Default Constructor Called" << std::endl;
	this->type = "abstractAnimal";
}

abstractAnimal::abstractAnimal(const abstractAnimal &copy)
{
	std::cout << "abstractAnimal Copy Constructor Called" << std::endl;
	this->type = copy.type;
}

abstractAnimal::~abstractAnimal()
{
	std::cout << "abstractAnimal Destructor Called" << std::endl;
}

abstractAnimal &abstractAnimal::operator=(const abstractAnimal &copy)
{
	std::cout << "abstractAnimal = Operator Overload Called" << std::endl;
	this->type = copy.type;
	return (*this);
}

std::string abstractAnimal::getType() const
{
	return (this->type);
}
