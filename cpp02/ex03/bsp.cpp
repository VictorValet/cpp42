/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:48:42 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/09 11:13:50 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool	same_half_plan(Point const seg_a, Point const seg_b,
			Point const point_a, Point const point_b)
{
	Fixed	ratio;
	Fixed	x;

	ratio = (seg_a.gety() - seg_b.gety()) / (seg_a.getx() - seg_b.getx());
	x = seg_a.getx() - (seg_a.gety() / ratio);
	if (ratio == INFINITY)
		return (point_b.getx() != seg_a.getx()
			&& (point_a.getx() < seg_a.getx())
			== (point_b.getx() < seg_a.getx()));
	if (ratio == 0)
		return (point_b.gety() != seg_a.gety()
			&& (point_a.gety() < seg_a.gety())
			== (point_b.gety() < seg_a.gety()));
	else
		return ((point_b.gety() != x + (point_b.getx() * ratio))
			&& (point_a.gety() < x + (point_a.getx() * ratio))
			== (point_b.gety() < x + (point_b.getx() * ratio)));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if ((a.getx() == b.getx() && a.getx() == c.getx()) 
		|| (a.gety() == b.gety() && a.gety() == c.gety()))
		return (false);
	if (same_half_plan(a, b, c, point) == false)
		return (false);
	if (same_half_plan(a, c, b, point) == false)
		return (false);
	if (same_half_plan(b, c, a, point) == false)
		return (false);
	return (true);
}