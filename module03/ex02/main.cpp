/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:36:18 by tabadawi          #+#    #+#             */
/*   Updated: 2024/12/24 08:07:57 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap clap("tarek");
	for (int i = 0; i < 5; i++)
		clap.attack("bad_clap");
	for (int i = 0; i < 11; i++)
		clap.takeDamage(1);
	clap.beRepaired(6);
	clap.highFivesGuys();
	return (0);
}