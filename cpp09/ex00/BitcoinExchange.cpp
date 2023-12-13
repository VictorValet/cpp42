/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:17:03 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/13 16:01:19 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &original)
{
	*this = original;
	return ;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &original)
{
	(void) original;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

bool	BitcoinExchange::isvalid(std::string line) const
{
	if (line.find('-', 0) != 4 || line.find('-', 5) != 7 || line.find(',', 8) != 10)
		return (false);
	for (unsigned int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (isdigit(line[i]) == false)
			return (false);
	}
	if (line.find('.', 11) != std::string::npos)
		line.erase(line.find('.', 11), 1);
	for (unsigned int i = 11; i < line.size(); i++)
	{
		if (isdigit(line[i]) == false)
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::isunique(std::string line) const
{
	std::map<std::string, double>::iterator	it;
	std::map<std::string, double>::iterator	ite = const_cast<BitcoinExchange *>(this)->end();
	for (it = const_cast<BitcoinExchange *>(this)->begin(); it != ite; it++)
	{
		if (it->first.compare(line.erase(11, line.size() - 1)) == 0)
			return (false);
	}
	return (true);
}

void	BitcoinExchange::addline(std::string line)
{
	if (isvalid(line) == false || isunique(line) == false)
		throw (ParsingException());
	std::string	key(line.substr(0, 10));
	double		value = atof(line.substr(12, line.size()).c_str());
	(*this)[key] = value;
}

void	BitcoinExchange::loadDB(const std::string file)
{
	std::ifstream	csv;
	std::string		buffer;
	csv.open(file, std::ios::in);
	if (csv.fail())
		throw (OpenFailureException());
	csv.ignore(256, '\n');
	while (!csv.eof())
	{
		getline(csv, buffer);
		if (buffer.empty() == false)
			addline(buffer);
		buffer.erase();
	}
	csv.close();
}

const char	*BitcoinExchange::OpenFailureException::what(void) const throw()
{
	return ("Failed to open file");
}

const char	*BitcoinExchange::ParsingException::what(void) const throw()
{
	return ("Parsing error");
}
