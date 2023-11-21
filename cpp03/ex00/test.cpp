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

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap floyd("Floyd");

	std::cout << floyd;
	floyd.takeDamage(5);
	floyd.attack("Jimbo");
	floyd.beRepaired(2);
	std::cout << floyd;
	floyd.takeDamage(20);
	floyd.attack("Jimbo");
	floyd.beRepaired(2);
	std::cout << floyd;
}
