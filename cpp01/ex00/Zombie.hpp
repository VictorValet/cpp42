/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:09:44 by vvalet            #+#    #+#             */
/*   Updated: 2023/10/30 15:51:13 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
		Zombie(std::string init_name);
		~Zombie(void);
		void	announce(void) const;

	private:
		std::string	name;
};

Zombie	*newZombie(std::string name);
void 	randomChump(std::string name);

#endif
