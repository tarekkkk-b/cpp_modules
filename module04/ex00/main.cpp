/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:42:43 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/01 17:12:20 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	//section 1
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;

	std::cout << "\n\n\n" << std::endl;

	//section 2

	const WrongAnimal *dummy1 = new WrongAnimal();
	const WrongAnimal *dummy2 = new WrongCat();

	std::cout << dummy1->getType() << " " << std::endl;
	std::cout << dummy2->getType() << " " << std::endl;

	dummy1->makeSound();
	dummy2->makeSound();

	delete dummy1;
	delete dummy2;
	
	return (0);
}
