/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:03:57 by vvalet            #+#    #+#             */
/*   Updated: 2023/07/27 15:33:54 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const	Fixed::n_bits = 8;

Fixed::Fixed(void):
raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &n)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = n;
	return ;
}

Fixed	&Fixed::operator=(Fixed const &N)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->raw_bits = N.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->raw_bits);
}

void	Fixed::setRawBits(int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->raw_bits = raw;
}
