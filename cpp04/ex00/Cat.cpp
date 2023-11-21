/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:19:24 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/14 13:55:41 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void):
Animal("cat")
{
	std::cout << "The new animal is a cat!\n";
	return ;
}

Cat::Cat(const Cat &original):
Animal(original.getType())
{
	std::cout << "The new animal is a cat!\n";
	return ;
}

Cat	&Cat::operator=(const Cat &original)
{
	(void) original;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "The cat is gone!\n";
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meeeooow!\n";
	return ;
}
