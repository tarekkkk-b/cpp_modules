/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:43:30 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/02 20:47:27 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public abstractAnimal
{
	private:
		Brain *head;

	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat &operator = (const Cat &copy);

		void makeSound() const;
		void thinkOutLoud() const;
		std::string rememberIdea(unsigned int i) const;
		void newIdea(unsigned int i, std::string idea);
};
