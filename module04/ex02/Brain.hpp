/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:25:12 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/02 17:07:29 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
	protected:
		std::string ideas[100];

	public:
		Brain();
		Brain(const std::string &idea);
		Brain(const Brain &copy);
		~Brain();
		Brain &operator = (const Brain &copy);

		void throwThoughts() const;
		void setIdea(unsigned int i, std::string idea);
		std::string getIdea(unsigned int i) const;
};