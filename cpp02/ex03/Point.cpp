/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:11:42 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/06 10:42:27 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void):x(0), y(0)
{
	return ;
}

Point::Point(const float i_x, const float i_y):x(i_x), y(i_y)
{
	return ;
}

Point::Point(const Point &n):x(n.x), y(n.y)
{
	return ;
}

Point	&Point::operator=(const Point &n)
{
	(void) n;
	return (*this);
}

Point::~Point(void)
{
	return ;
}

Fixed	Point::getx(void) const
{
	return (this->x);
}

Fixed	Point::gety(void) const
{
	return (this->y);
}

std::ostream	&operator<<(std::ostream &o, const Point &p)
{
	o << p.getx() << "," << p.gety();
	return (o);
}
