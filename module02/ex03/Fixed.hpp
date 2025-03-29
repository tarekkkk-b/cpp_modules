/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:32:28 by tabadawi          #+#    #+#             */
/*   Updated: 2024/12/12 12:56:45 by tabadawi         ###   ########.fr       */
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

	// CONSTRUCTORS AND DESTRUCTORS
	Fixed();
	Fixed(const Fixed &copy);
	Fixed(const int num);
	Fixed(const float flo);
	Fixed &operator=(const Fixed &copy);
	~Fixed();
	
	// SETTERS AND GETTERS
	int getRawBits() const;
	void setRawBits(int const raw);

	// TO FUNCTIONS
	float toFloat() const;
	int toInt() const;

	// COMPARISON OPERATORS
	bool operator > (const Fixed &b);
	bool operator < (const Fixed &b);
	bool operator >= (const Fixed &b);
	bool operator <= (const Fixed &b);
	bool operator == (const Fixed &b);
	bool operator != (const Fixed &b);
	
	// ARITHMETIC OPERATORS
	Fixed operator+(const Fixed &a) const;
	Fixed operator-(const Fixed &a) const;
	Fixed operator*(const Fixed &a) const;
	Fixed operator/(const Fixed &a) const;

	// ++/-- OPERATORS
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	// MEMBER FUNCTIONS
	static Fixed	&max(Fixed &a, Fixed &b);
	static Fixed	&max(const Fixed &a, const Fixed &b);
	static Fixed	&min(Fixed &a, Fixed &b);
	static Fixed	&min(const Fixed &a, const Fixed &b);
};

// OS OVERLOAD OPERATOR
std::ostream& operator<<(std::ostream& o, Fixed const & inst);