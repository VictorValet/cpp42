/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:08:18 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/14 13:44:30 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void):
type("Animal")
{
	std::cout << "Animal constructor called\n";
	return ;
}

Animal::Animal(const Animal &original):
type(original.getType())
{
	std::cout << "Animal constructor called\n";
	return ;
}

Animal::Animal(std::string const name):
type(name)
{
	std::cout << "Animal constructor called\n";
	return ;
}

Animal	&Animal::operator=(const Animal &original)
{
	(void) original;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called\n";
	return ;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "[Random animal sounds]\n";
}
