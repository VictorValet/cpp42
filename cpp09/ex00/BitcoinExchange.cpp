/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:17:03 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/14 10:28:22 by vvalet           ###   ########.fr       */
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

void	BitcoinExchange::isvalidDate(std::string line) const
{
	if (line.size() < 12 || line.find('-', 0) != 4 || line.find('-', 5) != 7 || line.find(',', 8) != 10)
		throw (ParsingException("wrong format (line: " + line + ")"));
	int	year = atoi(line.substr(0, 4).c_str());
	int	month = atoi(line.substr(5, 2).c_str());
	int	day = atoi(line.substr(8, 2).c_str());
	if (month > 12)
		throw (ParsingException("wrong format (line: " + line + ")"));
    if (day > 31)
		throw (ParsingException("wrong format (line: " + line + ")"));
    if (day == 31 and (month == 4 or month == 6 or month == 9 or month == 11))
		throw (ParsingException("wrong format (line: " + line + ")"));
    if (month == 2)
	{
      if (day > 29)
	  	throw (ParsingException("wrong format (line: " + line + ")"));
      if (day == 29 and ((year % 100) % 4 != 0))
	  	throw (ParsingException("wrong format (line: " + line + ")"));
	}
}

void	BitcoinExchange::isvalidFloat(std::string line) const
{
	if (line.find('.', 11) != std::string::npos)
		line.erase(line.find('.', 11), 1);
	for (unsigned int i = 11; i < line.size(); i++)
	{
		if (isdigit(line[i]) == false)
			throw (ParsingException("wrong format (line: " + line + ")"));
	}
}

void	BitcoinExchange::isunique(std::string line) const
{
	std::map<std::string, double>::iterator	it;
	std::map<std::string, double>::iterator	ite = const_cast<BitcoinExchange *>(this)->end();
	for (it = const_cast<BitcoinExchange *>(this)->begin(); it != ite; it++)
	{
		if (it->first.compare(line.substr(0, 10)) == 0)
			throw (ParsingException("date already exists (line: " + line + ")"));
	}
}

void	BitcoinExchange::addline(std::string line)
{
	try
	{
		isvalidDate(line);
		isvalidFloat(line);
		isunique(line);
		std::string	key(line.substr(0, 10));
		double		value = atof(line.substr(12, line.size()).c_str());
		(*this)[key] = value;
	}
	catch(const ParsingException& e)
	{
		std::cerr << e.what() << '\n';
	}
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

BitcoinExchange::ParsingException::ParsingException(const std::string str):
_str("Parsing error: " + str)
{
	return ;
}

BitcoinExchange::ParsingException::~ParsingException(void) throw()
{
	return ;
}

const char	*BitcoinExchange::ParsingException::what(void) const throw()
{
	return (this->_str.c_str());
}
