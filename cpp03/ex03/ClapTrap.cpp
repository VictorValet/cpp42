/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:03:23 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/16 09:22:04 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
name("noname"),
hit_points(10),
energy_points(10),
attack_damage(0),
type("ClapTrap")
{
	std::cout << "An unnamed ClapTrap comes to life!\n";
	return ;
}

ClapTrap::ClapTrap(std::string i_name):
name(i_name),
hit_points(10),
energy_points(10),
attack_damage(0),
type("ClapTrap")
{
	std::cout << "ClapTrap " << this->name << " comes to life!\n";
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &c):
name(c.getName()),
hit_points(c.getHitPoints()),
energy_points(c.getEnergyPoints()),
attack_damage(c.getAttackDamage()),
type("ClapTrap")
{
	std::cout << "ClapTrap " << this->name << " comes to life!\n";
	return ;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &c)
{
	this->hit_points = c.getHitPoints();
	this->energy_points = c.getEnergyPoints();
	this->attack_damage = c.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " returns to the abysses!\n";
	return ;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->hit_points == 0)
		std::cout << this->type << " " << this->name << " is KO. Cannot attack.\n";	
	else if (this->energy_points == 0)
		std::cout << this->type << " " << this->name << " has no energy left. Cannot attack.\n";	
	else
	{
		std::cout << this->type << " " << this->name << " attacks target " << target
			<< " causing " << this->attack_damage << " points of damage!\n";
		this->energy_points--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points == 0)
		std::cout << this->type << " " << this->name << " is KO. Cannot take more damage.\n";
	else
	{
		std::cout << this->type << " " << this->name << " takes " << amount
			<< " points of damage!\n";
		this->hit_points -= amount;
		if (this->hit_points < 0)
			this->hit_points = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
		if (this->hit_points == 0)
			std::cout << this->type << " " << this->name << " is KO. Cannot be repaired.\n";
		else if (this->energy_points == 0)
			std::cout << this->type << " " << this->name << " has no energy left. Cannot be repaired.\n";
		else
		{
			std::cout << this->type << " " << this->name << " gets healed " << amount
				<< " points.\n";
			this->hit_points += amount;
			this->energy_points--;
		}
}

std::string	ClapTrap::getName(void) const
{
	return (this->name);	
}

int	ClapTrap::getHitPoints(void) const
{
	return (this->hit_points);	
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (this->energy_points);	
}

int	ClapTrap::getAttackDamage(void) const
{
	return (this->attack_damage);	
}

std::string	ClapTrap::getType(void) const
{
	return (this->type);	
}

std::ostream	&operator<<(std::ostream &o, const ClapTrap &c)
{
	o << c.getType() << " " << c.getName() << ":" << std::endl
		<< "Hit points: " << c.getHitPoints() << std::endl
		<< "Energy points: " << c.getEnergyPoints() << std::endl
		<< "Attack damage: " << c.getAttackDamage() << std::endl;
	return (o);
}
