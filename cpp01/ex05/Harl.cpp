/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:39:46 by vvalet            #+#    #+#             */
/*   Updated: 2023/10/31 14:45:34 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

std::string const Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(void)
{
	fct[0] = &Harl::debug;
	fct[1] = &Harl::info;
	fct[2] = &Harl::warning;
	fct[3] = &Harl::error;
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::complain(std::string level) const
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (level == levels[i])
			break;
		i++;
	}
	if (i < 4)
		(this->*fct[i])();
}

void	Harl::debug(void) const
{
	std::cout	<< "I love having extra bacon for my 7XL-double-cheese-"
				<< "triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::info(void) const
{
	std::cout	<< "I cannot believe adding extra bacon costs more money. You didn't put"
				<< " enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void	Harl::warning(void) const
{
	std::cout	<< "I think I deserve to have some extra bacon for free. I've been"
				<< " coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void) const
{
	std::cout	<< "This is unacceptable! I want to speak to the manager now.\n";
}
