/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:10:05 by vvalet            #+#    #+#             */
/*   Updated: 2023/10/30 15:47:27 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *allan;
	Zombie *bryan;
	
	allan = newZombie("Allan");
	allan->announce();
	bryan = newZombie("Bryan");
	bryan->announce();
	randomChump("Carl");
	randomChump("Dennis");
	delete allan;
	delete bryan;
	return (0);
}
