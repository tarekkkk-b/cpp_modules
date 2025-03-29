/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:32:25 by tabadawi          #+#    #+#             */
/*   Updated: 2024/12/12 12:55:07 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	area(Point const a, Point const b, Point const c)
{
	Fixed	total = ((a.getPointX() * (b.getPointY() - c.getPointY())) \
					+ (b.getPointX() * (c.getPointY() - a.getPointY())) \
					+ (c.getPointX() * (a.getPointY() - b.getPointY()))) / Fixed(2);
	return (std::fabs(total.toFloat()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float full = area(a, b, c);
	float sub1 = area(point, b, c);
	float sub2 = area(a, point, c);
	float sub3 = area(a, b, point);
	if (!full || !sub1 || !sub2 || !sub3)
		return (false);	
	return ((sub1 + sub2 + sub3) == full);
}
