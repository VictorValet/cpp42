/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:08:48 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/16 14:52:33 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void):
name("")
{
	int	i;

	i = 0;
	while (i < 4)
	{
		this->inventory[i] = NULL;
		i++;
	}
	return ;
}

Character::Character(std::string const &str):
name(str)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		this->inventory[i] = NULL;
		i++;
	}
	return ;
}

Character::Character(const Character &original):
name(original.getName())
{
	int	i;

	i = 0;
	while (i < 4)
	{
		this->inventory[i] = NULL;
		equip(original.getInventory(i)->clone());
		i++;
	}
	return ;
}

Character	&Character::operator=(const Character &original)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (this->inventory[i] != NULL)
		{	
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		if (original.getInventory(i) != NULL)
			this->equip(original.getInventory(i)->clone());
		i++;
	}
	return (*this);
}

Character::~Character(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (this->inventory[i] != NULL)
		{	
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		i++;
	}
	return ;
}

std::string const	&Character::getName() const
{
	return (this->name);
}

const AMateria	*Character::getInventory(int i) const
{
	return (this->inventory[i]);	
}

void	Character::equip(AMateria* m)
{
	int	i;

	i = 0;
	if (m == NULL)
		return ;
	while (i < 4)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return ;
		}
		i++;
	}
	return ;
}

void	Character::unequip(int idx)
{
	if (idx < 4 && this->inventory[idx] != NULL)
	{
		this->inventory[idx] = NULL;
	}
	return ;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && this->inventory[idx] != NULL)
	{
		this->inventory[idx]->use(target);
	}
	return ;
}
