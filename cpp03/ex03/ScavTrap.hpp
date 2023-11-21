/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:34:33 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/14 12:25:06 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(std::string i_name);
		~ScavTrap(void);
		void	attack(const std::string &target);
		void	guardGate(void);

	protected:
		ScavTrap(void);

	private:
		ScavTrap(const ScavTrap &n);
		ScavTrap	&operator=(const ScavTrap &n);
};

#endif
