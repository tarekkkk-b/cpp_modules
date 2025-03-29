/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:05:02 by tabadawi          #+#    #+#             */
/*   Updated: 2024/12/24 08:08:33 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("tarek");
	for (int i = 0; i < 5; i++)
		clap.attack("bad_clap");
	for (int i = 0; i < 11; i++)
		clap.takeDamage(1);
	clap.beRepaired(6);
	return (0);
}