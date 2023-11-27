/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:07:29 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/27 12:30:18 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <time.h>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string new_target);
		~RobotomyRequestForm(void);
		void	execute(Bureaucrat const &executor) const;

	private:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &original);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &original);
};

#endif
