/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:29:40 by tabadawi          #+#    #+#             */
/*   Updated: 2024/12/09 15:14:22 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constuctor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constuctor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destuctor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constuctor called" << std::endl;
	this->value = num << fraction;
}

Fixed::Fixed(const float flo)
{
	std::cout << "Float constuctor called" << std::endl;
	this->value = static_cast<int>(roundf(flo * (1 << fraction)));
}

float Fixed::toFloat() const
{
	return (static_cast<float>(value) / (1 << fraction));
}

int Fixed::toInt() const
{
	return (value / (1 << fraction));
}

Fixed &Fixed::operator = (const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = copy.value;
	return (*this);
}

std::ostream& operator<<(std::ostream &o, Fixed const &inst)
{
	o << inst.toFloat();
	return (o);
}
