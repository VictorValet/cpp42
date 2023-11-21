/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:19:24 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/16 14:37:11 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void):
Animal("cat")
{
	std::cout << "The new animal is a cat!\n";
	this->brain = new Brain();
	return ;
}

Cat::Cat(const Cat &original):
Animal(original.getType())
{
	std::cout << "The new animal is a cat!\n";
	this->brain = new Brain(original.getBrain());
	return ;
}

Cat	&Cat::operator=(const Cat &original)
{
	*this->brain = original.getBrain();
	return (*this);
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "The cat is gone!\n";
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meeeooow!\n";
	return ;
}

Brain	Cat::getBrain(void) const
{
	return (*this->brain);
}

void	Cat::setIdea(int i, std::string str)
{
	if (i > -1 && i < 100)
		this->brain->ideas[i] = str;
	return ;
}

std::string	Cat::getIdea(int i) const
{
	if (i > -1 && i < 100)
		return (this->brain->ideas[i]);
	else
		return ("wrong index\n");
}
