/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:08:18 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/08 13:26:04 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void):
type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called\n";
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &original):
type(original.getType())
{
	std::cout << "WrongAnimal constructor called\n";
	return ;
}

WrongAnimal::WrongAnimal(std::string const name):
type(name)
{
	std::cout << "WrongAnimal constructor called\n";
	return ;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &original)
{
	(void) original;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called\n";
	return ;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "[Random WrongAnimal wrong sounds]\n";
}
