/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:23:45 by vvalet            #+#    #+#             */
/*   Updated: 2023/10/31 10:18:13 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB
{
	public:
		HumanB(std::string init_name);
		~HumanB(void);
		void	setWeapon(Weapon &new_weapon);
		void	attack(void) const;

	private:
		const std::string	name;
		Weapon				*weapon;
};

#endif
