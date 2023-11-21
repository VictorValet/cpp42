/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:23:40 by vvalet            #+#    #+#             */
/*   Updated: 2023/10/31 10:10:59 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string init_name, Weapon &init_weapon):
name(init_name),
weapon(init_weapon)
{
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}

void	HumanA::setWeapon(Weapon &new_weapon)
{
	this->weapon = new_weapon;
}

void	HumanA::attack(void) const
{
	std::cout	<< this->name << " attacks with their " 
				<< this->weapon.getType() << std::endl;
}
