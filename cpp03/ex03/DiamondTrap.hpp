/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:27:48 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/14 10:32:19 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(std::string name);
		~DiamondTrap(void);
		using	ScavTrap::attack;
		void	whoAmI(void);

	private:
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap &n);
		DiamondTrap	&operator=(const DiamondTrap &n);
		const std::string	name;
};

#endif
