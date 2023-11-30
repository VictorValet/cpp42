/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data_conv.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:59:26 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/30 14:39:58 by vvalet           ###   ########.fr       */
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
	str.pop_back();
	if (is_double(str) != true)
		return (false);
	else
		return (true);
}

static void	convert_char(std::string str, Data &d)
{
	d.setChar(str[1]);
	d.setInt(static_cast<int>(d.getChar()));
	d.setFloat(static_cast<float>(d.getChar()));
	d.setDouble(static_cast<double>(d.getChar()));
	d.printC(str[1]);
	d.printI(str[1]);
	d.printF();
	d.printD();
}

static void	convert_int(std::string str, Data &d)
{
	int			v;
	long long	l;

	l = atoll(str.c_str());
	v = atoll(str.c_str());
	if (static_cast<long long>(v) != l)
		throw (Data::ConversionErrorException("Int conversion overflow"));
	d.setInt(static_cast<int>(v));
	d.setChar(static_cast<char>(v));
	d.setFloat(static_cast<float>(v));
	d.setDouble(static_cast<double>(v));
	d.printC(l);
	d.printI(l);
	d.printF();
	d.printD();
}

static void	convert_double(std::string str, Data &d)
{
	double	v;

	v = atof(str.c_str());
	d.setInt(static_cast<int>(v));
	d.setChar(static_cast<char>(v));
	d.setFloat(static_cast<float>(v));
	d.setDouble(static_cast<double>(v));
	d.printC(v);
	d.printI(v);
	d.printF();
	d.printD();
}

static void	convert_float(std::string str, Data &d)
{
	float		v;

	v = atof(str.c_str());
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
			convert[i](str, *this);
			return ;
		}
	}
	throw (ConversionErrorException("Unknown data type"));
	return ;
}

bool	(*Data::type[4])(std::string) = 
	{is_char, is_int, is_float, is_double};

void	(*Data::convert[4])(std::string, Data &) =
	{convert_char, convert_int, convert_float, convert_double};
