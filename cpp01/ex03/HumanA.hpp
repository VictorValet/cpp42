/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:23:42 by vvalet            #+#    #+#             */
/*   Updated: 2023/10/31 10:18:05 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanA
{
	public:
		HumanA(std::string init_name, Weapon &init_weapon);
		~HumanA(void);
		void	setWeapon(Weapon &new_weapon);
		void	attack(void) const;

	private:
		const std::string	name;
		Weapon				&weapon;
};

#endif
