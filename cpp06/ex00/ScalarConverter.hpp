/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:41:27 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/28 13:43:12 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	public:
		~ScalarConverter(void);
		static void	convert(std::string str);

	protected:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &original);
		ScalarConverter	&operator=(const ScalarConverter &original);
};

#endif
