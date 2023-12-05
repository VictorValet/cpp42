/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:41:27 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/05 11:59:43 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include "Data.hpp"

class ScalarConverter
{
	public:
		~ScalarConverter(void);
		static void	convert(std::string str);

	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &original);
		ScalarConverter	&operator=(const ScalarConverter &original);
};

#endif
