/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:52:33 by tabadawi          #+#    #+#             */
/*   Updated: 2024/12/09 15:14:41 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream> 

class	Fixed
{
	private:
	int					value;
	static const int	fraction = 8;

	public:
	Fixed();
	Fixed(const Fixed &copy);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);
	Fixed &operator = (const Fixed &copy);
};
