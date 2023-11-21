/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:10:05 by vvalet            #+#    #+#             */
/*   Updated: 2023/10/30 15:58:36 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *allans;
	Zombie *bryans;
	Zombie *carls;
	
	allans = zombieHorde(3, "Allan");
	for (int i = 0; i < 3; i++)
		allans[i].announce();
	bryans = zombieHorde(2, "Bryan");
	for (int i = 0; i < 2; i++)
		bryans[i].announce();
	carls = zombieHorde(4, "Carl");
	for (int i = 0; i < 4; i++)
		carls[i].announce();
	delete [] allans;
	delete [] bryans;
	delete [] carls;
	return (0);
}
