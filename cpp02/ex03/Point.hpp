/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:11:44 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/06 12:00:32 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float i_x, const float i_y);
		Point(const Point &n);
		~Point(void);
		Fixed	getx(void) const;
		Fixed	gety(void) const;

	private:
		Point	&operator=(const Point &n);
		Fixed const	x;
		Fixed const	y;
};

std::ostream	&operator<<(std::ostream &o, const Point &p);

bool			bsp(Point const a, Point const b, Point const c, Point const point);

#endif
