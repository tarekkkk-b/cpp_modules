/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:43:28 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/02 21:34:13 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog Default Constructor Called" << std::endl;
	this->type = "Dog";
	this->head = new Brain("i got a bone to pick");
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
	this->type = copy.type;
	if (copy.head)
		this->head = new Brain(*copy.head);
	else
		this->head = 0;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" << std::endl;
	delete this->head;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog = Operator Overload Called" << std::endl; 	
	this->type = copy.type;
	if (this->head)
		delete this->head;
	if (copy.head)
		this->head = new Brain(*copy.head);
	else
		this->head = 0;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF" << std::endl;
}

void Dog::thinkOutLoud() const
{
	this->head->throwThoughts();
}

std::string Dog::rememberIdea(unsigned int i) const
{
	return (this->head->getIdea(i));
}

void Dog::newIdea(unsigned int i, std::string idea)
{
this->head->setIdea(i, idea);
}
