/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:58:33 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/09 10:16:03 by vvalet           ###   ########.fr       */
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

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->raw_bits = value << this->n_bits;
	return ;
}

Fixed::Fixed(float const value)
{
	float	f;

	std::cout << "Float constructor called" << std::endl;
	f = value * pow(2, this->n_bits);
	this->raw_bits = (int)roundf(f);
	return ;
}

Fixed::Fixed(Fixed const &n)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = n;
	return ;
}

Fixed	&Fixed::operator=(Fixed const &n)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->raw_bits = n.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->raw_bits);
}

void	Fixed::setRawBits(int raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->raw_bits = raw;
}

float	Fixed::toFloat(void) const
{
	float	f;

	f = this->raw_bits / pow(2, this->n_bits);
	return (f);
}

int		Fixed::toInt(void) const
{
	return (this->raw_bits >> this->n_bits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &f)
{
	o << f.toFloat();
	return (o);
}
