/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:41:05 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/13 10:07:25 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void):
AMateria("ice")
{
	return ;
}

Ice::Ice(const Ice &original):
AMateria("ice")
{
	(void) original;
	return ;
}

Ice	&Ice::operator=(const Ice &original)
{
	(void) original;
	return (*this);
}

Ice::~Ice(void)
{
	return ;
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
	return ;
}
