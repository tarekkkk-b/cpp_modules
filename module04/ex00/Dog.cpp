/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:43:28 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/01 19:16:46 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog Default Constructor Called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
	this->type = copy.type;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog = Operator Overload Called" << std::endl;
	this->type = copy.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF" << std::endl;
}
