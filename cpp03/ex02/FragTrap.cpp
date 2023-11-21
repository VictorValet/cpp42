/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:34:47 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/14 13:01:07 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->type = "FragTrap";
	std::cout << "It has a FragTrap personnality!\n";
	return ;
}

FragTrap::FragTrap(std::string i_name):
ClapTrap(i_name)
{
	this->type = "FragTrap";
	std::cout << "It has a FragTrap personnality!\n";
	return ;
}

FragTrap::FragTrap(const FragTrap &c):
ClapTrap(c.getName())
{
	this->hit_points = c.getHitPoints();
	this->energy_points = c.getEnergyPoints();
	this->attack_damage = c.getAttackDamage();
	this->type = "FragTrap";
	std::cout << "It has a FragTrap personnality!\n";
	return ;
}

FragTrap	&FragTrap::operator=(const FragTrap &c)
{
	this->hit_points = c.getHitPoints();
	this->energy_points = c.getEnergyPoints();
	this->attack_damage = c.getAttackDamage();
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << this->name << "'s FragTrap personnality is destroyed.\n";
	return ;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->type << " " << this->name << " asks for a high five.\n";
	return ;
}
