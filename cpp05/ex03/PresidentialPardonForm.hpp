/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:08:08 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/27 12:01:50 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string new_target);
		~PresidentialPardonForm(void);
		void	execute(Bureaucrat const &executor) const;

	private:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &original);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &original);
};

#endif

