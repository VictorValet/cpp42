/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:27:46 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/14 12:33:41 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):
ClapTrap("noname_clap_name")
{
	this->type = "DiamondTrap";
	std::cout << "It has a DiamondTrap personnality!\n";
	return ;
}

DiamondTrap::DiamondTrap(std::string i_name):
ClapTrap(i_name + "_clap_name"),
name(i_name)
{
	this->type = "DiamondTrap";
	std::cout << "It has a DiamondTrap personnality!\n";
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &c):
ClapTrap(c.getName())
{
	this->hit_points = c.getHitPoints();
	this->energy_points = c.getEnergyPoints();
	this->attack_damage = c.getAttackDamage();
	this->type = "DiamondTrap";
	std::cout << "It has a DiamondTrap personnality!\n";
	return ;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &c)
{
	this->hit_points = c.getHitPoints();
	this->energy_points = c.getEnergyPoints();
	this->attack_damage = c.getAttackDamage();
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << this->ClapTrap::name << "'s DiamondTrap personnality is destroyed.\n";
	return ;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->name << ", " << ClapTrap::name << std::endl;
}
