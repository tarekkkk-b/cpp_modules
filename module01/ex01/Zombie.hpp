/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:14:18 by tabadawi          #+#    #+#             */
/*   Updated: 2024/08/29 21:30:19 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
	private:
	std::string name;

	public:
	Zombie();
	void announce();
	void setName(std::string name);
	Zombie(std::string name);
	~Zombie();
};

Zombie* zombieHorde(int N, std::string name);