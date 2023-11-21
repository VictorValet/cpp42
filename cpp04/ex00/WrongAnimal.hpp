/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:08:22 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/08 13:16:40 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		virtual ~WrongAnimal(void);
		std::string		getType(void) const;
		void			makeSound(void) const;

	protected:
		WrongAnimal(std::string const name);
		std::string	type;

	private:
		WrongAnimal(const WrongAnimal &original);
		WrongAnimal	&operator=(const WrongAnimal &original);
};

#endif
