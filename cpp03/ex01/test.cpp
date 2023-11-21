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

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap floyd("Floyd");
	ClapTrap john("John");

	std::cout << floyd;
	floyd.takeDamage(50);
	floyd.attack("Jimbo");
	john.attack("Jimbo");
	floyd.beRepaired(20);
	floyd.guardGate();
	std::cout << floyd;
	floyd.takeDamage(80);
	floyd.attack("Jimbo");
	floyd.beRepaired(10);
	std::cout << floyd;
}
