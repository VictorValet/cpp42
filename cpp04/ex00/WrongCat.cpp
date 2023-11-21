/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:19:24 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/08 13:25:50 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void):
WrongAnimal("WrongCat")
{
	std::cout << "The new animal is a WrongCat!\n";
	return ;
}

WrongCat::WrongCat(const WrongCat &original):
WrongAnimal(original.getType())
{
	std::cout << "The new animal is a WrongCat!\n";
	return ;
}

WrongCat	&WrongCat::operator=(const WrongCat &original)
{
	(void) original;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "The WrongCat is gone!\n";
	return ;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meeeooow!\n";
	return ;
}
