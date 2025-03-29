/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:30:44 by tabadawi          #+#    #+#             */
/*   Updated: 2024/09/28 20:16:56 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "[ Harl forgot how to complain ]" << std::endl;
		return (1);
	}
	std::string complaint = av[1];
	Harl	harl;
	harl.complain(complaint);
}