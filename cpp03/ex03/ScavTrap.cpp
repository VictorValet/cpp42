/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:34:47 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/14 12:59:10 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->energy_points = 50;
	this->type = "ScavTrap";
	std::cout << "It has a ScavTrap personnality!\n";
	return ;
}

ScavTrap::ScavTrap(std::string i_name):
ClapTrap(i_name)
{
	this->type = "ScavTrap";
	std::cout << "It has a ScavTrap personnality!\n";
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &c):
ClapTrap(c.getName())
{
	this->hit_points = c.getHitPoints();
	this->energy_points = c.getEnergyPoints();
	this->attack_damage = c.getAttackDamage();
	this->type = "ScavTrap";
	std::cout << "It has a ScavTrap personnality!\n";
	return ;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &c)
{
	this->hit_points = c.getHitPoints();
	this->energy_points = c.getEnergyPoints();
	this->attack_damage = c.getAttackDamage();
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->name << "'s ScavTrap personnality is destroyed.\n";
	return ;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->hit_points == 0)
		std::cout << this->type << " " << this->name << " is KO. Cannot punch its opponent.\n";	
	else if (this->energy_points == 0)
		std::cout << this->type << " " << this->name << " has no energy left. Cannot punch its opponent.\n";	
	else
	{
		std::cout << this->type << " " << this->name << " punch opponent " << target
			<< " causing " << this->attack_damage << " points of damage!\n";
		this->energy_points--;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << this->type << " " << this->name << " has enter Gate Keeper mode.\n";
	return ;
}
