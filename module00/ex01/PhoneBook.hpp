/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:47:45 by tabadawi          #+#    #+#             */
/*   Updated: 2024/08/29 14:15:37 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

#pragma once

class	PhoneBook
{
	private:
	Contact	contacts[8];
	int count;

	public:
	PhoneBook();
	void	set_contact(Contact c, int i);
	Contact	get_contact(int	i);
	void	inc_count();
	int		get_count();
};