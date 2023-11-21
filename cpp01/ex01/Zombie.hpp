/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:09:44 by vvalet            #+#    #+#             */
/*   Updated: 2023/10/30 15:51:45 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
	
		Zombie(void);
		~Zombie(void);
		void	announce(void) const;
		void	setname(std::string new_name);
		
	private:
		std::string	name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif