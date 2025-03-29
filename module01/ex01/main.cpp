/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:14:28 by tabadawi          #+#    #+#             */
/*   Updated: 2024/08/29 21:33:26 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int count = 10;
	Zombie* horde = zombieHorde(count, "pierce");
	int i = -1;
	while (++i < count)
		horde[i].announce();
	delete[] horde;
}