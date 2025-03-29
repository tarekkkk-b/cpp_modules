/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:42:43 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/02 18:57:39 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <limits.h>

int main()
{
	//section 1
	
	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();

	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;

	// i->makeSound();
	// j->makeSound();
	// meta->makeSound();
	// delete i;
	// delete j;
	// delete meta;

	// std::cout << "\n\n\n" << std::endl;

	//section 2

	// const WrongAnimal *dummy1 = new WrongAnimal();
	// const WrongAnimal *dummy2 = new WrongCat();

	// std::cout << dummy1->getType() << " " << std::endl;
	// std::cout << dummy2->getType() << " " << std::endl;

	// dummy1->makeSound();
	// dummy2->makeSound();

	// delete dummy1;
	// delete dummy2;

	//section 3

	const Animal *animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete animals[i];

	Dog *hey = new Dog();
	hey->thinkOutLoud();
	std::cout << hey->rememberIdea(99) << std::endl;
	delete hey;

	return (0);
}
