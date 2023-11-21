/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:41:05 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/10 15:52:19 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void):
AMateria("cure")
{
	return ;
}

Cure::Cure(const Cure &original):
AMateria("cure")
{
	(void) original;
	return ;
}

Cure	&Cure::operator=(const Cure &original)
{
	(void) original;
	return (*this);
}

Cure::~Cure(void)
{
	return ;
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
	return ;
}
