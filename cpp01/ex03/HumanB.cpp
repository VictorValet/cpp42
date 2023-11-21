/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:23:43 by vvalet            #+#    #+#             */
/*   Updated: 2023/10/31 10:16:06 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string init_name):
name(init_name),
weapon(NULL)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	this->weapon = &new_weapon;
}

void	HumanB::attack(void) const
{
	if (this->weapon == NULL)
		std::cout	<< this->name << " doesn't have any weapon...\n";
	else
		std::cout	<< this->name << " attacks with their " 
					<< (*this->weapon).getType() << std::endl;
}
