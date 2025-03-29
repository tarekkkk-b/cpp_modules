/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:52:37 by tabadawi          #+#    #+#             */
/*   Updated: 2024/08/29 13:33:29 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Contact
{
	private:
	std::string	fname;
	std::string	lname;
	std::string	nname;
	std::string	number;
	std::string	secret;

	public:
	Contact();
	Contact(std::string fname, std::string lname, std::string nname, \
		std::string number, std::string secret);
	
	void			set_fname(std::string fname);
	void			set_lname(std::string lname);
	void			set_nname(std::string nname);
	void			set_number(std::string number);
	void			set_secret(std::string secret);
	std::string		get_fname();
	std::string		get_secret();
	std::string		get_lname();
	std::string		get_number();
	std::string		get_nname();
};
