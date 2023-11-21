/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:36:12 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/21 15:31:31 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap floyd("Floyd");

	std::cout << floyd;
	floyd.attack("Jimbo");
	floyd.beRepaired(20);
	floyd.takeDamage(50);
	floyd.guardGate();
	floyd.highFivesGuys();
	floyd.whoAmI();
	std::cout << floyd;
	floyd.takeDamage(80);
	floyd.attack("Jimbo");
	floyd.beRepaired(10);
	std::cout << floyd;
}
