/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:35:31 by tabadawi          #+#    #+#             */
/*   Updated: 2024/12/23 20:08:38 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap: public ScavTrap, FragTrap
{
	private:
		std::string name;
	
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap(std::string name);
		DiamondTrap &operator=(const DiamondTrap &copy);
		~DiamondTrap();
		void attack(std::string target);
		void whoAmI();
};