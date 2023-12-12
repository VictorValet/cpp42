/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:31:32 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/12 14:36:16 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void):
_max(0)
{
	return ;
}

Span::Span(unsigned int n):
_max(n)
{
	return ;
}

Span::Span(const Span &original):
_max(original.getMax())
{
	*this = original;
	return ;
}

Span	&Span::operator=(const Span &original)
{
	if (original.getNumbers().size() > this->_max)
		throw (NoSpaceException());
	this->_numbers = original.getNumbers();
	return (*this);
}

Span::~Span(void)
{
	return ;
}

std::vector<int>	Span::getNumbers(void) const
{
	return (this->_numbers);
}

unsigned int	Span::getMax(void) const
{
	return (this->_max);
}

std::vector<int>::const_iterator	Span::begin(void) const
{
	return (this->_numbers.begin());	
}

std::vector<int>::const_iterator	Span::end(void) const
{
	return (this->_numbers.end());	
}


void	Span::addNumber(int i)
{
	if (this->_numbers.size() == this->_max)
		throw (NoSpaceException());
	this->_numbers.push_back(i);
}

unsigned int	Span::shortestSpan(void) const
{
	if (this->_numbers.size() == 0 || this->_numbers.size() == 1)
		throw (NoSpanException());
	std::vector<int>::iterator	it = const_cast<Span *>(this)->_numbers.begin();
	std::vector<int>::iterator	ite = const_cast<Span *>(this)->_numbers.end();
	std::sort(it, ite);
	unsigned int	diff = UINT_MAX;
	int				previous = *this->_numbers.begin();
	for (it = ++const_cast<Span *>(this)->_numbers.begin(); it != ite; ++it)
	{
		if (static_cast<unsigned int>(*it - previous) < diff)
			diff = *it - previous;
		previous = *it;
	}
	return (diff);
}

unsigned int	Span::longestSpan(void) const
{
	if (this->_numbers.size() == 0 || this->_numbers.size() == 1)
		throw (NoSpanException());
	std::vector<int>::const_iterator	it = this->_numbers.begin();
	std::vector<int>::const_iterator	ite = this->_numbers.end();
	int min = *std::min_element(it, ite);
	int max = *std::max_element(it, ite);
	return (max - min);
}

const char	*Span::NoSpaceException::what() const throw()
{
	return ("No space left to store numbers");
}

const char	*Span::NoSpanException::what() const throw()
{
	return ("No span can be found");
}

std::ostream	&operator<<(std::ostream &o, Span &s)
{
	std::vector<int>::const_iterator it;
	std::vector<int>::const_iterator ite = s.end();
	for (it = s.begin(); it != ite; it++)
		o << *it << std::endl;
	return (o);
}
