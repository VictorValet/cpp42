/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:08:50 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/13 14:07:07 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>

class Character : public ICharacter
{
	public:
		Character(std::string const &str);
		Character(const Character &original);
		Character	&operator=(const Character &original);
		~Character(void);
		std::string const	&getName() const;
		const AMateria		*getInventory(int i) const;
		void 				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

	private:
		Character(void);
		std::string const	name;
		AMateria			*inventory[4];
};

#endif
