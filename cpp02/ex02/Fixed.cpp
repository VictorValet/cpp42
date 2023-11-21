/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:58:33 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/06 09:47:45 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const	Fixed::n_bits = 8;

Fixed::Fixed(void):
raw_bits(0)
{
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->raw_bits = value << this->n_bits;
	return ;
}

Fixed::Fixed(float const value)
{
	float	f;

	// std::cout << "Float constructor called" << std::endl;
	f = value * pow(2, this->n_bits);
	this->raw_bits = (int)roundf(f);
	return ;
}

Fixed::Fixed(const Fixed &n)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = n;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &n)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->raw_bits = n.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
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

bool	Fixed::operator>(const Fixed &n) const
{
	return (this->raw_bits > n.getRawBits());
}

bool	Fixed::operator<(const Fixed &n) const
{
	return (this->raw_bits < n.getRawBits());
}

bool	Fixed::operator>=(const Fixed &n) const
{
	return (this->raw_bits >= n.getRawBits());
}

bool	Fixed::operator<=(const Fixed &n) const
{
	return (this->raw_bits <= n.getRawBits());
}

bool	Fixed::operator==(const Fixed &n) const
{
	return (this->raw_bits == n.getRawBits());
}

bool	Fixed::operator!=(const Fixed &n) const
{
	return (this->raw_bits != n.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &n) const
{
	Fixed	result(this->toFloat() + n.toFloat());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &n) const
{
	Fixed	result(this->toFloat() - n.toFloat());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &n) const
{
	Fixed	result(this->toFloat() * n.toFloat());
	return (result);
}

Fixed	Fixed::operator/(const Fixed &n) const
{
	Fixed	result(this->toFloat() / n.toFloat());
	return (result);
}

Fixed	&Fixed::operator++(void)
{
	raw_bits++;
	return (*this);
}

Fixed	Fixed::operator++(int n)
{
	Fixed	old(*this);

	(void)	n;
	this->operator++();
	return (old);
}

Fixed	&Fixed::operator--(void)
{
	raw_bits--;
	return (*this);
}

Fixed	Fixed::operator--(int n)
{
	Fixed	old(*this);

	(void)	n;
	this->operator--();
	return (old);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() <= b.getRawBits())
		return(a);
	else
		return(b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() <= b.getRawBits())
		return(a);
	else
		return(b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return(a);
	else
		return(b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return(a);
	else
		return(b);
}

std::ostream	&operator<<(std::ostream &o, const Fixed &f)
{
	o << f.toFloat();
	return (o);
}
