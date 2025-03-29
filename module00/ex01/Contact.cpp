/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:50:53 by tabadawi          #+#    #+#             */
/*   Updated: 2024/08/29 13:39:23 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}
Contact::Contact(std::string fname, std::string lname, std::string nname, \
std::string number, std::string secret)
{
	this->fname = fname;
	this->lname = lname;
	this->nname = nname;
	this->number = number;
	this->secret = secret;
}

void	Contact::set_fname(std::string fname)
{
	this->fname=fname;
}
std::string	Contact::get_fname()
{	
	return fname;
}
void	Contact::set_lname(std::string lname)
{
	this->lname=lname;
}
std::string	Contact::get_lname()
{
	return lname;
}
void	Contact::set_nname(std::string nname)
{
	this->nname=nname;
}
std::string	Contact::get_nname()
{	
	return nname;
}
void	Contact::set_number(std::string number)
{
	this->number=number;
}
std::string	Contact::get_number()
{
	return number;
}
void	Contact::set_secret(std::string secret)
{
	this->secret=secret;
}
std::string	Contact::get_secret()
{
	return secret;
}
