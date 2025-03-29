/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:32:37 by tabadawi          #+#    #+#             */
/*   Updated: 2024/12/11 18:55:05 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class	Point
{
	private:
	const Fixed	x;
	const Fixed	y;

	public:

	// CONSTRUCTRS AND DESTRUCTORS
	Point();
	Point(const float x, const float y);
	Point(const int x_v, const int y_v);
	Point(const Point &copy);
	Point &operator=(const Point &copy);
	~Point();
	
	// SETTERS AND GETTERS
	// void setPoints(const Fixed &x, const Fixed &y);
	const Fixed &getPointX() const;
	const Fixed &getPointY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);