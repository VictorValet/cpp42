/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:25:06 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/16 13:43:42 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brand new brain!\n";
	return ;
}

Brain::Brain(const Brain &original)
{
	*this = original;
	return ;
}

Brain	&Brain::operator=(const Brain &original)
{
	int i = 0;

	while (i < 100)
	{
		this->ideas[i] = original.ideas[i];
		i++;
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain death...\n";
	return ;
}
