/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:03:59 by vvalet            #+#    #+#             */
/*   Updated: 2023/07/27 15:34:58 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:	
		Fixed(void);
		Fixed(int const	value);
		Fixed(float const value);
		Fixed(Fixed const &n);
		Fixed	&operator=(Fixed const &n);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	
	private:
		int					raw_bits;
		static int const	n_bits;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &f);

#endif
