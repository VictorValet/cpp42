/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:08:22 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/14 16:45:01 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	public:
		AAnimal(void);
		virtual ~AAnimal(void);
		std::string		getType(void) const;
		virtual	void	makeSound(void) const = 0;

	protected:
		AAnimal(std::string const name);
		std::string	type;

	private:
		AAnimal(const AAnimal &original);
		AAnimal	&operator=(const AAnimal &original);
};

#endif
