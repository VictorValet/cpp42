/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:14:09 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/16 15:03:56 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		this->known[i] = NULL;
		i++;
	}
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &original)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		this->known[i] = NULL;
		learnMateria(original.getKnown(i)->clone());
		i++;
	}
	return ;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &original)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (this->known[i] != NULL)
		{	
			delete this->known[i];
			this->known[i] = NULL;
		}
		if (original.getKnown(i) != NULL)
			this->learnMateria((AMateria *)original.getKnown(i));
		i++;
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (this->known[i] != NULL)
		{	
			delete this->known[i];
			this->known[i] = NULL;
		}
		i++;
	}
	return ;
}

const AMateria	*MateriaSource::getKnown(int i) const
{
	return (this->known[i]);	
}

void	MateriaSource::learnMateria(AMateria *m)
{
	int	i;

	i = 0;
	if (m == NULL)
		return ;
	while (i < 4)
	{
		if (this->known[i] == NULL)
		{
			this->known[i] = m;
			return ;
		}
		i++;
	}
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (this->known[i] != NULL && this->known[i]->getType().compare(type) == 0)
			return (this->known[i]->clone());
		i++;
	}
	return (NULL);
}
