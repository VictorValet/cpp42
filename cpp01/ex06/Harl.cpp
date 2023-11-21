/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:39:46 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/02 10:54:23 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

std::string const Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(void)
{
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
	switch (i)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break ;
		case 4:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void	Harl::debug(void) const
{
	std::cout	<< "[DEBUG]" << std::endl
				<< "I love having extra bacon for my 7XL-double-cheese-"
				<< "triple-pickle-special-ketchup burger. I really do!"
				<< std::endl << std::endl;
}

void	Harl::info(void) const
{
	std::cout	<< "[INFO]" << std::endl
				<< "I cannot believe adding extra bacon costs more money. You didn't put"
				<< " enough bacon in my burger! If you did, I wouldn't be asking for more!"
				<< std::endl << std::endl;
}

void	Harl::warning(void) const
{
	std::cout	<< "[WARNING]" << std::endl
				<< "I think I deserve to have some extra bacon for free. I've been"
				<< " coming for years whereas you started working here since last month."
				<< std::endl << std::endl;
}

void	Harl::error(void) const
{
	std::cout	<< "[ERROR]" << std::endl
				<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl << std::endl;
}
