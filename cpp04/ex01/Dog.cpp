/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:19:50 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/16 14:37:01 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void):
Animal("dog")
{
	std::cout << "The new animal is a dog!\n";
	this->brain = new Brain();
	return ;
}

Dog::Dog(const Dog &original):
Animal(original.getType())
{
	std::cout << "The new animal is a dog!\n";
	this->brain = new Brain(original.getBrain());
	return ;
}

Dog	&Dog::operator=(const Dog &original)
{
	*this->brain = original.getBrain();
	return (*this);
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "The dog is gone!\n";
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "Waf waf!\n";
	return ;
}

Brain	Dog::getBrain(void) const
{
	return (*this->brain);
}

void	Dog::setIdea(int i, std::string str)
{
	if (i > -1 && i < 100)
		this->brain->ideas[i] = str;
	return ;
}

std::string	Dog::getIdea(int i) const
{
	if (i > -1 && i < 100)
		return (this->brain->ideas[i]);
	else
		return ("wrong index\n");
}
