/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:25:09 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/02 17:09:05 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Well that is an idea";
	std::cout << "Brain Default Constructor Called" << std::endl;
}

Brain::Brain(const std::string &idea)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
	std::cout << "Brain Idea Constructor Called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy Constructor Called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain Destructor Called" << std::endl;
}

Brain &Brain::operator=(const Brain & copy)
{
	std::cout << "Brain = Operator Overload Called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return (*this);
}

void Brain::throwThoughts() const
{
	for (int i = 0; i < 100; i++)
		std::cout << this->ideas[i] << std::endl;
}

void Brain::setIdea(unsigned int i, std::string idea)
{
	if (i > 100)
		std::cout << "your cute lil brain can't have more than a hunnid ideas" << std::endl;
	else
		this->ideas[i] = idea;
}

std::string Brain::getIdea(unsigned int i) const
{
	std::string extra = "you dont have that many ideas buddy";
	if (i > 100)
		return (extra);
	return (this->ideas[i]);
}
