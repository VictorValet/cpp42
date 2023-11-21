/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:34:33 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/14 10:13:17 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
# define FragTrap_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(std::string i_name);
		~FragTrap(void);
		void	highFivesGuys(void);

	protected:
		FragTrap(void);

	private:
		FragTrap(const FragTrap &n);
		FragTrap	&operator=(const FragTrap &n);
};

#endif
