/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:16:46 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/05 10:16:46 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void):
i(0)
{
	return ;
}

Data::Data(int x):
i(x)
{
	return ;
}

Data::Data(const Data &original)
{
	*this = original;
	return ;
}

Data	&Data::operator=(const Data &original)
{
	this->i = original.getI();
	return (*this);
}

Data::~Data(void)
{
	return ;
}

int		Data::getI(void) const
{
	return(this->i);
}

void	Data::setI(int x)
{
	this->i = x;
}
