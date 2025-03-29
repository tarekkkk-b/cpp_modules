/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:12:53 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/10 15:34:27 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	// std::cout << "from main, type is " << tmp->getType() << std::endl;
	me->equip(tmp);

	tmp = src->createMateria("cure");
	// std::cout << "from main, type is " << tmp->getType() << std::endl;
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	AMateria *free = ((Character *)me)->getAddress(0);
	me->unequip(0);
	delete free;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(0, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}