/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:41:13 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/10 15:45:16 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAL_HPP
# define HEAL_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &original);
		Cure	&operator=(const Cure &original);
		~Cure(void);
		AMateria*	clone() const;
		void 		use(ICharacter& target);

	private:
};

#endif
