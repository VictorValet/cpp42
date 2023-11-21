/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:08:22 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/14 16:37:21 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal(void);
		virtual ~Animal(void);
		std::string			getType(void) const;
		virtual	void		makeSound(void) const;

	protected:
		Animal(std::string const name);
		std::string	type;

	private:
		Animal(const Animal &original);
		Animal	&operator=(const Animal &original);
};

#endif
