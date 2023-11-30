/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:41:29 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/30 14:21:49 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &original)
{
	(void) original;
	return ;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &original)
{
	(void) original;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}

void	ScalarConverter::convert(std::string str)
{
	try
	{
		Data data(str);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
