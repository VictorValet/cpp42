/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:19:53 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/14 16:07:04 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &original);
		Dog	&operator=(const Dog &original);
		~Dog(void);
		void		makeSound(void) const;
		Brain		getBrain(void) const;
		void		setIdea(int i, std::string str);
		std::string getIdea(int i) const;

	private:
		Brain	*brain;
};

#endif
