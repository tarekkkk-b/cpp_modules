/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:32:21 by tabadawi          #+#    #+#             */
/*   Updated: 2024/12/11 12:28:20 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// CONSTRUCTORS AND DESTRUCTORS

Fixed::Fixed()
{
	// std::cout << "Default constuctor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy constuctor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int num)
{
	// std::cout << "Int constuctor called" << std::endl;
	this->value = num << fraction;
}

Fixed::Fixed(const float flo)
{
	// std::cout << "Float constuctor called" << std::endl;
	this->value = static_cast<int>(roundf(flo * (1 << fraction)));
}

Fixed &Fixed::operator = (const Fixed &copy)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->value = copy.value;
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destuctor called" << std::endl;
}

// SETTERS AND GETTERS

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

// TO FUNCTIONS

float Fixed::toFloat() const
{
	return (static_cast<float>(value) / (1 << fraction));
}

int Fixed::toInt() const
{
	return (value / (1 << fraction));
}

// COMPARISON OPERATORS

bool Fixed::operator > (const Fixed &b)
{
    return (this->getRawBits() > b.getRawBits());
}

bool Fixed::operator < (const Fixed &b)
{
    return (this->getRawBits() < b.getRawBits());
}

bool Fixed::operator >= (const Fixed &b)
{
    return (this->getRawBits() >= b.getRawBits());
}

bool Fixed::operator <= (const Fixed &b)
{
    return (this->getRawBits() <= b.getRawBits());
}

bool Fixed::operator == (const Fixed &b)
{
    return (this->getRawBits() == b.getRawBits());
}

bool Fixed::operator != (const Fixed &b)
{
    return (this->getRawBits() != b.getRawBits());
}

// ARITHMETIC OPERATORS

Fixed Fixed::operator+(const Fixed &a) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() + a.getRawBits()));
	return (result);
}

Fixed Fixed::operator-(const Fixed &a) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - a.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &a) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() * a.getRawBits()) / (1 << fraction));
	return (result);
}

Fixed Fixed::operator/(const Fixed &a) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() * (1 << fraction)) / a.getRawBits());
	return (result);
}

// ++/-- OPERATORS

Fixed &Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->value++;
	return (temp);
}

Fixed &Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->value--;
	return (temp);
}

// MEMBER FUNCTIONS

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return ((Fixed &)a);
	return ((Fixed &)b);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return ((Fixed &)a);
	return ((Fixed &)b);
}

// OS OVERLOAD OPERATOR

std::ostream& operator<<(std::ostream &o, Fixed const &inst)
{
	o << inst.toFloat();
	return (o);
}
