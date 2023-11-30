/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:59:26 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/30 14:37:35 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void):
c(0), i(0), f(0), d(0)
{
	return ;
}

Data::Data(const Data &original)
{
	*this = original;
	return ;
}

Data	&Data::operator=(const Data &original)
{
	c = original.getChar();
	i = original.getInt();
	f = original.getFloat();
	d = original.getDouble();
	return (*this);
}

Data::~Data(void)
{
	return ;
}

char	Data::getChar(void) const
{
	return (this->c);
}

int	Data::getInt(void) const
{
	return (this->i);
}

float	Data::getFloat(void) const
{
	return (this->f);
}

double	Data::getDouble(void) const
{
	return (this->d);
}

void	Data::setChar(char new_c)
{
	this->c = new_c;
}

void	Data::setInt(int new_i)
{
	this->i = new_i;
}

void	Data::setFloat(float new_f)
{
	this->f = new_f;
}

void	Data::setDouble(double new_d)
{
	this->d = new_d;
}

void	Data::printC(long long l)
{
	std::cout << "char: ";
	if (l >= 32 && l <= 126)
		std::cout << '\'' << this->c << '\'' << std::endl;
	else if (l >= 0 && l <= 127)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void	Data::printI(double l)
{
	std::cout << "int: ";
	if (l <= INT_MAX && l >= INT_MIN)
		std::cout << this->i << std::endl;
	else if (l == INFINITY || l == -INFINITY || l != l)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "overflow" << std::endl;
}

void	Data::printF(void)
{
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(4) << this->f << "f" << std::endl;
}

void	Data::printD(void)
{
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(4) << this->d << std::endl;
}

Data::ConversionErrorException::ConversionErrorException(const std::string str):
text(str)
{
	return ;
}
				
Data::ConversionErrorException::~ConversionErrorException(void) throw()
{
	return ;
}

const char	*Data::ConversionErrorException::what() const throw()
{
	return (this->text.c_str());
}
