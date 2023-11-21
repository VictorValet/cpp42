/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:09:56 by vvalet            #+#    #+#             */
/*   Updated: 2023/10/30 15:59:21 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->name + " died\n";
	return ;
}

void	Zombie::announce(void) const
{
	std::cout << this->name + ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setname(std::string new_name)
{
	this->name = new_name;
}
