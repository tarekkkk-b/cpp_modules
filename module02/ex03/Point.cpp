/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:32:34 by tabadawi          #+#    #+#             */
/*   Updated: 2024/12/12 12:47:56 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// CONSTRUCTRS AND DESTRUCTORS
Point::Point() : x(0), y(0)
{
}

Point::Point(const float x_v, const float y_v) : x(x_v), y(y_v)
{
}

Point::Point(const int x_v, const int y_v) : x(x_v), y(y_v)
{
}
Point::Point(const Point &copy) : x(copy.x), y(copy.y)
{
}

Point &Point::operator=(const Point &copy)
{
	(void)copy;
	return (*this);
}

Point::~Point()
{	
}

// SETTERS AND GETTERS
const Fixed &Point::getPointX() const
{
	return (this->x);
}

const Fixed &Point::getPointY() const
{
	return (this->y);
}
