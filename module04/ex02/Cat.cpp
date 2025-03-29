/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:43:32 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/02 21:08:03 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : abstractAnimal()
{
	std::cout << "Cat Default Constructor Called" << std::endl;
	this->type = "Cat";
	this->head = new Brain("where is jerry");
}

Cat::Cat(const Cat &copy) : abstractAnimal(copy)
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
	this->type = copy.type;
	if (copy.head)
		this->head = new Brain(*copy.head);
	else
		this->head = 0;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
	delete this->head;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat = Operator Overload Called" << std::endl;
	this->type = copy.type;
	if (this->head)
		delete this->head;
	if (copy.head)
		this->head = new Brain(*copy.head);
	else
		this->head = 0;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "MEOW MEOW" << std::endl;
}

void Cat::thinkOutLoud() const
{
	this->head->throwThoughts();
}

std::string Cat::rememberIdea(unsigned int i) const
{
	return (this->head->getIdea(i));
}

void Cat::newIdea(unsigned int i, std::string idea)
{
this->head->setIdea(i, idea);
}
