/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:09:56 by vvalet            #+#    #+#             */
/*   Updated: 2023/10/30 16:02:55 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string init_name): name(init_name)
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
	std::cout << this->name + ": BraiiiiiiinnnzzzZ...\n" ;
}
