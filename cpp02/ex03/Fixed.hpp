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
		Fixed(const Fixed &n);
		Fixed	&operator=(const Fixed &n);
		~Fixed(void);
		int					getRawBits(void) const;
		void				setRawBits(int raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		bool				operator>(const Fixed &n) const;
		bool				operator<(const Fixed &n) const;
		bool				operator>=(const Fixed &n) const;
		bool				operator<=(const Fixed &n) const;
		bool				operator==(const Fixed &n) const;
		bool				operator!=(const Fixed &n) const;
		Fixed				operator+(const Fixed &n) const;
		Fixed				operator-(const Fixed &n) const;
		Fixed				operator*(const Fixed &n) const;
		Fixed				operator/(const Fixed &n) const;
		Fixed				&operator++(void);
		Fixed				operator++(int n);
		Fixed				&operator--(void);
		Fixed				operator--(int n);
		static Fixed		&min(Fixed &a, Fixed &b);
		const static Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		const static Fixed	&max(const Fixed &a, const Fixed &b);

	private:
		int					raw_bits;
		static int const	n_bits;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &f);

#endif
