/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:02:39 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/10 12:55:20 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>
#include <iostream>

int main( void ) 
{
	Fixed x;
	Fixed const y( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << x << std::endl;
	std::cout << ++x << std::endl;
	std::cout << x << std::endl;
	std::cout << x++ << std::endl;
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << Fixed::max( x, y ) << std::endl;

	Fixed a( 2 );
	Fixed b( 10 );
	Fixed c( 42.42f );
	Fixed d( 1.5f );
	Fixed e( 1.5f );
	Fixed f( 2.0f );
	
	std::cout << std::left;
	std::cout << std::endl << "comparison:" << std::endl;
	std::cout << std::setw(8) << d << std::setw(4) << " == " << std::setw(8) << e << " = " << (d == e) << std::endl;
	std::cout << std::setw(8) << a << std::setw(4) << " == " << std::setw(8) << e << " = " << (a == e) << std::endl;
	std::cout << std::setw(8) << d << std::setw(4) << " != " << std::setw(8) << e << " = " << (d != e) << std::endl;
	std::cout << std::setw(8) << a << std::setw(4) << " != " << std::setw(8) << e << " = " << (a != e) << std::endl;
	std::cout << std::setw(8) << d << std::setw(4) << " <= " << std::setw(8) << e << " = " << (d <= e) << std::endl;
	std::cout << std::setw(8) << a << std::setw(4) << " <= " << std::setw(8) << f << " = " << (a <= f) << std::endl;
	std::cout << std::setw(8) << a << std::setw(4) << " <  " << std::setw(8) << f << " = " << (a < f) << std::endl;
	std::cout << std::setw(8) << a << std::setw(4) << " >= " << std::setw(8) << f << " = " << (a >= f) << std::endl;
	std::cout << std::setw(8) << a << std::setw(4) << " >  " << std::setw(8) << f << " = " << (a > f) << std::endl;
	std::cout << std::endl << "arithmetic:" << std::endl;
	std::cout << std::setw(8) << a << std::setw(4) << " +  " << std::setw(8) << a << " = " << (a + a) << std::endl;
	std::cout << std::setw(8) << a << std::setw(4) << " -  " << std::setw(8) << b << " = " << (a - b) << std::endl;
	std::cout << std::setw(8) << b << std::setw(4) << " *  " << std::setw(8) << d << " = " << (b * d) << std::endl;
	std::cout << std::setw(8) << b << std::setw(4) << " /  " << std::setw(8) << a << " = " << (b / a) << std::endl;
	std::cout << std::setw(8) << c << std::setw(4) << " /  " << std::setw(8) << d << " = " << (c / d) << std::endl;
	std::cout << std::endl << "increment/decrement:" << std::endl;
	std::cout << "a   = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a   = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a   = " << a << std::endl;
	std::cout << "b   = " << b << std::endl;
	std::cout << "--b = " << --b << std::endl;
	std::cout << "b   = " << b << std::endl;
	std::cout << "b-- = " << b-- << std::endl;
	std::cout << "b   = " << b << std::endl;
	std::cout << std::endl << "max/min:" << std::endl;
	std::cout << "max = " << Fixed::max( a, b ) << std::endl;
	std::cout << "min = " << Fixed::min( a, b ) << std::endl;
	std::cout << "max = " << Fixed::max( (const Fixed &) a, (const Fixed &) b ) << std::endl;
	std::cout << "min = " << Fixed::min( (const Fixed &) a, (const Fixed &) b ) << std::endl;
	return 0;
}
