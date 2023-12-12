/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:31:32 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/12 12:08:20 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


#include <iostream>

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

std::list<int>	Span::getNumbers(void) const
{
	return (this->_numbers);
}

unsigned int	Span::getMax(void) const
{
	return (this->_max);
}

std::list<int>::iterator	Span::begin(void)
{
	return (this->_numbers.begin());	
}

std::list<int>::iterator	Span::end(void)
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
	const_cast<Span *>(this)->_numbers.sort();
	std::list<int>::const_iterator	it;
	std::list<int>::const_iterator	ite = this->_numbers.end();
	unsigned int	diff = UINT_MAX;
	int				previous = *this->_numbers.begin();
	for (it = ++this->_numbers.begin(); it != ite; ++it)
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
	std::list<int>::const_iterator	it = this->_numbers.begin();
	std::list<int>::const_iterator	ite = this->_numbers.end();
	int min = *std::min_element(it, ite);
	int max = *std::max_element(it, ite);
	return (max - min);
}

void	Span::fillNumbers(std::list<int>::iterator first, std::list<int>::iterator last)
{
	unsigned int	range = std::distance(first, last);
	if (range > this->_max)
		throw (NoSpaceException());
	this->_numbers.erase(first, last);
	srand (time(NULL));
	while (range-- > 0)
		this->addNumber(rand());
}


const char	*Span::NoSpaceException::what() const throw()
{
	return ("No space left to store numbers");
}

const char	*Span::NoSpanException::what() const throw()
{
	return ("No span can be found");
}

/* Alternative versions */
// void	Span::addNumber(int i)
// {
// 	if (this->_numbers.size() == this->_max)
// 		throw (NoSpaceException());
// 	std::list<int>::const_iterator	it = this->_numbers.begin();
// 	std::list<int>::const_iterator	ite = this->_numbers.end();
// 	while (i > *it && it != ite)
// 		it++;
// 	this->_numbers.insert(it, i);
// }

// unsigned int	Span::shortestSpan(void) const //pas ultra optimisé
// {
// 	if (this->_numbers.size() == 0 || this->_numbers.size() == 1)
// 		throw (NoSpanException());
// 	std::list<int>::const_iterator	it;
// 	std::list<int>::const_iterator	ite = this->_numbers.end();
// 	unsigned int	diff = UINT_MAX;
// 	int				previous = *this->_numbers.begin();
// 	for (it = ++this->_numbers.begin(); it != ite; ++it)
// 	{
// 		if (static_cast<unsigned int>(*it - previous) < diff)
// 			diff = *it - previous;
// 		previous = *it;
// 	}
// 	return (diff);
// }

// unsigned int	Span::longestSpan(void) const
// {
// 	if (this->_numbers.size() == 0 || this->_numbers.size() == 1)
// 		throw (NoSpanException());
// 	const_cast<Span *>(this)->_numbers.sort();
// 	int min = this->_numbers.front();
// 	int max = this->_numbers.back();
// 	return (max - min);
// }
