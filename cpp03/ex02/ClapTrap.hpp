/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:03:25 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/14 12:24:35 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string i_name);
		~ClapTrap(void);
		virtual void	attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		std::string		getName(void) const;
		int				getHitPoints(void) const;
		int				getEnergyPoints(void) const;
		int				getAttackDamage(void) const;
		std::string		getType(void) const;

	protected:
		ClapTrap(void);
		const std::string	name;
		int					hit_points;
		int					energy_points;
		int					attack_damage;
		std::string			type;

	private:
		ClapTrap(const ClapTrap &n);
		ClapTrap	&operator=(const ClapTrap &n);
};

std::ostream	&operator<<(std::ostream &o, const ClapTrap &c);

#endif
