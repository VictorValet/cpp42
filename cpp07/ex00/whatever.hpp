/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:21:54 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/05 10:32:09 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T &x, T &y)
{
	T temp;
	
	temp = x;
	x = y;
	y = temp;
}

template<typename T>
const T	&min(const T &x, const T &y)
{
	return ((x < y) ? x : y);
}

template<typename T>
const T	&max(const T &x, const T &y)
{
	return ((x > y) ? x : y);
}

#endif
