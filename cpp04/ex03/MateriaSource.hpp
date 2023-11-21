/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:14:07 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/13 15:08:27 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &original);
		MateriaSource	&operator=(const MateriaSource &original);
		~MateriaSource(void);
		const AMateria	*getKnown(int i) const;
		void			learnMateria(AMateria*);
		AMateria*		createMateria(std::string const &type);

	private:
		AMateria			*known[4];
};

#endif
