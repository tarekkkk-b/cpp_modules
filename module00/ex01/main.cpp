/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:32:19 by tabadawi          #+#    #+#             */
/*   Updated: 2024/08/29 14:46:31 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	print_menu()
{
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "|		 ADD			|" << std::endl;
	std::cout << "|		SEARCH			|" << std::endl;
	std::cout << "|		 EXIT			|" << std::endl;
	std::cout << "-----------------------------------------" << std::endl << std::endl;
}

int		validate_str(std::string str, int flag)
{
	if (flag == 2)
		return (1);
	for (int i = 0; i < (int)str.size(); i++){
		if (flag){
			if (!isalpha(str[i])){
			std::cout << "Invalid Name.\n";
			return (0);
			}
		}
		else if (!flag){
			if (!isdigit(str[i])){	
			std::cout << "Invalid Number.\n";
			return (0);
			}
		}
	}
	return (1);
}

std::string	get_string(std::string message, int flag)
{
	std::string str;
	std::cout << message;
	std::getline(std::cin, str);
	if (std::cin.eof()){
		std::cout << "\n*NSYNC - BYE BYE BYE!\n\n";
		exit(0);
	}
	while (!validate_str(str, flag) || str.empty()){
		std::cout << message;
		std::getline(std::cin, str);
		if (std::cin.eof()){
			std::cout << "\n*NSYNC - BYE BYE BYE!\n\n";
			exit(0);
		}
	}
	return(str);
}

void	add_contact(PhoneBook *the_phonebook, int i)
{
	Contact temp;
	temp.set_fname(get_string("First Name: ", 1));
	temp.set_lname(get_string("Last Name: ", 1));
	temp.set_nname(get_string("Nickname: ", 2));
	temp.set_number(get_string("Number: ", 0));
	temp.set_secret(get_string("Darkest secret: ", 2));
	if (the_phonebook->get_count() < 7)
		the_phonebook->inc_count();
	the_phonebook->set_contact(temp, i);
}

void	print_phone_book(PhoneBook the_phonebook)
{
	int i = -1;
	int count = 0;
	std::cout << "---------------------------------------------\n";
	std::cout << "|     index|first name| last name|  nickname|\n";
	std::cout << "---------------------------------------------\n";
	while (++i < 8){
		std::cout << "|         " << i << "|";
		if (the_phonebook.get_contact(i).get_fname().size() > 10){
			std::cout << the_phonebook.get_contact(i).get_fname().substr(0, 9).append(".|");
		}
		else{
			while ((the_phonebook.get_contact(i).get_fname().size() + count) < 10){
				std::cout << " ";
				count++;
			}
			std::cout << the_phonebook.get_contact(i).get_fname() << "|";
			count = 0;
		}
		if (the_phonebook.get_contact(i).get_lname().size() > 10){
			std::cout << the_phonebook.get_contact(i).get_lname().substr(0, 9).append(".|");
		}
		else{
			while ((the_phonebook.get_contact(i).get_lname().size() + count) < 10){
				std::cout << " ";
				count++;
			}
			std::cout << the_phonebook.get_contact(i).get_lname() << "|";
			count = 0;
		}
		if (the_phonebook.get_contact(i).get_nname().size() > 10){
			std::cout << the_phonebook.get_contact(i).get_nname().substr(0, 9).append(".|");
		}
		else{
			while ((the_phonebook.get_contact(i).get_nname().size() + count) < 10){
				std::cout << " ";
				count++;
			}
			std::cout << the_phonebook.get_contact(i).get_nname() << "|";
			count = 0;
		}
		std::cout << std::endl;;
	}
	std::cout << "---------------------------------------------\n";
}

void	print_contact(PhoneBook the_phonebook, int i)
{
	if (!(i >= 0 && i <= 7)){
		std::cout << "pick an index from within the range.\n";
		return ;
	}
	if (i > the_phonebook.get_count()){
		std::cout << "No contact found." << std::endl;
		return ;
	}
	std::cout << "First Name: " << the_phonebook.get_contact(i).get_fname() << std::endl;
	std::cout << "Last Name: " << the_phonebook.get_contact(i).get_lname() << std::endl;
	std::cout << "Nickname: " << the_phonebook.get_contact(i).get_nname() << std::endl;
	std::cout << "Number: " << the_phonebook.get_contact(i).get_number() << std::endl;
	std::cout << "Darkest Secret: : " << the_phonebook.get_contact(i).get_secret() << std::endl;
}

int main()
{
	PhoneBook	the_phonebook;
	std::string str;
	std::string index;
	std::cout << "\n	Weclome to your PHONEBOOK!\n\n";
	print_menu();
	int i = 0;
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, str);
		if (std::cin.eof()){
			std::cout << "\n*NSYNC - BYE BYE BYE!\n\n";
			exit(0);
		}
		if (str == "ADD"){
			add_contact(&the_phonebook, i);
			i++;
			if (i == 8)
				i = 0;
		}
		else if (str == "SEARCH"){
			print_phone_book(the_phonebook);
			std::cout << "select an index from 0 - 7\nindex: ";
			std::getline(std::cin, index);
			if (std::cin.eof()){
				std::cout << "\n*NSYNC - BYE BYE BYE!\n\n";
				exit(0);
			}
			if (validate_str(index, 0))
				print_contact(the_phonebook, atoi(index.c_str()));
		}
		else if (str == "EXIT"){
			std::cout << "\n*NSYNC - BYE BYE BYE!\n\n";
			return 0;
		}
		else{
		std::cout << "\nplease use one of the available options:\n\n";
		print_menu();}
	}
}
