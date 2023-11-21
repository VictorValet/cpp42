/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:35:53 by vvalet            #+#    #+#             */
/*   Updated: 2023/10/31 14:45:28 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
# define HARL_CPP

# include <string>

class Harl
{
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level) const;

	private:
		const static std::string	levels[4];
		void						(Harl::*fct[4])(void) const;
		void	debug(void) const;
		void	info(void) const;
		void	warning(void) const;
		void	error(void) const;
};

#endif
