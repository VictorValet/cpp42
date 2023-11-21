/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:08:18 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/08 13:26:04 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void):
type("AAnimal")
{
	std::cout << "AAnimal constructor called\n";
	return ;
}

AAnimal::AAnimal(const AAnimal &original):
type(original.getType())
{
	std::cout << "AAnimal constructor called\n";
	return ;
}

AAnimal::AAnimal(std::string const name):
type(name)
{
	std::cout << "AAnimal constructor called\n";
	return ;
}

AAnimal	&AAnimal::operator=(const AAnimal &original)
{
	(void) original;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called\n";
	return ;
}

std::string	AAnimal::getType(void) const
{
	return (this->type);
}
