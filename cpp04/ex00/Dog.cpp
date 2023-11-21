/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:19:50 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/14 13:55:47 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void):
Animal("dog")
{
	std::cout << "The new animal is a dog!\n";
	return ;
}

Dog::Dog(const Dog &original):
Animal(original.getType())
{
	std::cout << "The new animal is a dog!\n";
	return ;
}

Dog	&Dog::operator=(const Dog &original)
{
	(void) original;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "The dog is gone!\n";
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "Waf waf!\n";
	return ;
}
