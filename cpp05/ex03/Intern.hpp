/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:48:42 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/27 16:48:43 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &original);
		Intern	&operator=(const Intern &original);
		~Intern(void);
		AForm	*makeForm(std::string name, std::string new_target);

	private:
};

#endif
