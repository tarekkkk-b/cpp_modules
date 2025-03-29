/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:46:11 by tabadawi          #+#    #+#             */
/*   Updated: 2024/08/29 14:14:19 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->count = -1;
}
void	PhoneBook::set_contact(Contact c, int i)
{
	contacts[i] = c;
}
Contact	PhoneBook::get_contact(int	i)
{
	return contacts[i];
}

void	PhoneBook::inc_count()
{
	this->count++;
}

int	PhoneBook::get_count()
{
	return (count);
}
