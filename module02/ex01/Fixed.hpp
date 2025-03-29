/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:29:36 by tabadawi          #+#    #+#             */
/*   Updated: 2024/12/04 20:51:58 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
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
	Fixed &operator=(const Fixed &copy);
	
	int getRawBits() const;
	void setRawBits(int const raw);

	Fixed(const int num);
	Fixed(const float flo);
	float toFloat() const;
	int toInt() const;
};

std::ostream& operator<<(std::ostream& o, Fixed const & inst);