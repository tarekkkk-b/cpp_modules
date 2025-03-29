/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:47:00 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/02 20:40:24 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class abstractAnimal
{
	protected:
		std::string type;
	
	public:
		abstractAnimal();
		abstractAnimal(const abstractAnimal &copy);
		virtual ~abstractAnimal();
		abstractAnimal &operator = (const abstractAnimal &copy);
		
		virtual void makeSound() const = 0;
		std::string getType() const;
};
