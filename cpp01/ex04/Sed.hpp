/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:54:27 by vvalet            #+#    #+#             */
/*   Updated: 2023/10/31 14:06:41 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <fstream>
# include <string>

class Sed
{
	public:
		Sed(char const *file, char const *s, char const *r);
		~Sed(void);
		bool	replace(void);
		
	private:
		const std::string	searched;
		const std::string	replacer;
		std::ifstream		infile;
		std::ofstream		outfile;		
		std::string			buffer;
		int					state;
};

#endif
