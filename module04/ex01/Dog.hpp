/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:43:25 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/02 17:16:57 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *head;

	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog &operator = (const Dog &copy);

		void makeSound() const;
		void thinkOutLoud() const;
		std::string rememberIdea(unsigned int i) const;
		void newIdea(unsigned int i, std::string idea);
};
