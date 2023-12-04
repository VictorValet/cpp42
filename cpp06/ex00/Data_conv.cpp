/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data_conv.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:59:26 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/04 14:14:56 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

static bool	is_char(std::string str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return (true);
	return (false);
}

static bool	is_int(std::string str)
{
	if (str[0] != '-' && str[0] != '+' && isdigit(str[0]) == false)
		return (false);
	for (size_t i = 1; i < str.length(); i++)
	{
		if (isdigit(str[i]) == false)
			return (false);
	}
	return (true);
}

static bool	is_double(std::string str)
{
	bool	dot;

	dot = false;
	if (str[0] != '-' && str[0] != '+' && isdigit(str[0]) == false)
		return (false);
	for (size_t i = 1; i < (str.length() - 1); i++)
	{
		if (dot == false && str[i] == '.')
			dot = true;
		else if (isdigit(str[i]) == false)
			return (false);
	}
	return (dot);
}

static bool	is_float(std::string str)
{
	if (str[str.length() - 1] != 'f')
		return (false);
	str[str.length() - 1] = 0;
	if (is_double(str) != true)
		return (false);
	else
		return (true);
}

static void	convert(std::string str, Data &d)
{
	double v;

	v = strtod(str.c_str(), NULL);
	d.setInt(static_cast<int>(v));
	d.setChar(static_cast<char>(v));
	d.setFloat(static_cast<float>(v));
	d.setDouble(static_cast<double>(v));
	d.printC(v);
	d.printI(v);
	d.printF();
	d.printD();
}

Data::Data(std::string str)
{
	for (int i = 0; i < 4; i++)
	{
		if (type[i](str) == true)
		{
			convert(str, *this);
			return ;
		}
	}
	throw (ConversionErrorException("Unknown data type"));
	return ;
}

bool	(*Data::type[4])(std::string) = 
	{is_char, is_int, is_float, is_double};
