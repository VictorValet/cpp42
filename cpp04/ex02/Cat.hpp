/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:19:28 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/14 16:45:42 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat(void);
		Cat(const Cat &original);
		Cat	&operator=(const Cat &original);
		~Cat(void);
		void		makeSound(void) const;
		Brain		getBrain(void) const;
		void		setIdea(int i, std::string str);
		std::string getIdea(int i) const;

	private:
		Brain	*brain;
};

#endif
