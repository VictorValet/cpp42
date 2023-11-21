/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:09:43 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/13 13:58:35 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void):
type("")
{
	return ;
}

AMateria::AMateria(std::string const &str):
type(str)
{
	return ;
}

AMateria::AMateria(const AMateria &original):
type("")
{
	(void) original;
	return ;
}

AMateria	&AMateria::operator=(const AMateria &original)
{
	(void) original;
	return (*this);
}

AMateria::~AMateria(void)
{
	return ;
}

std::string const	&AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter &target)
{
	(void) target;
	return ;
}
