/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:36:18 by tabadawi          #+#    #+#             */
/*   Updated: 2024/12/24 08:08:21 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap clap("tarek");
	for (int i = 0; i < 5; i++)
		clap.attack("bad_clap");
	for (int i = 0; i < 11; i++)
		clap.takeDamage(1);
	clap.beRepaired(6);
	clap.guardGate();
	return (0);
}