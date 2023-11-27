/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:03:47 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/27 16:05:05 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <cstdlib>
# include <time.h>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string new_target);
		~ShrubberyCreationForm(void);
		void	execute(Bureaucrat const &executor) const;

	private:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &original);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &original);
};

#endif
