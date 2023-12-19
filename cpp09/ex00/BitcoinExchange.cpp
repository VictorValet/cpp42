/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:17:03 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/19 11:01:21 by vvalet           ###   ########.fr       */
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

void	BitcoinExchange::isvalidDate(std::string line, std::string sep) const
{
	if (line.find('-', 0) != 4 || line.find('-', 5) != 7 || line.find(sep, 8) != 10)
		throw (LineException("wrong date format (line: " + line + ")"));
	int	year = atoi(line.substr(0, 4).c_str());
	int	month = atoi(line.substr(5, 2).c_str());
	int	day = atoi(line.substr(8, 2).c_str());
	if (month > 12)
		throw (LineException("wrong date format (line: " + line + ")"));
    if (day > 31)
		throw (LineException("wrong date format (line: " + line + ")"));
    if (day == 31 and (month == 4 or month == 6 or month == 9 or month == 11))
		throw (LineException("wrong date format (line: " + line + ")"));
    if (month == 2)
	{
      if (day > 29)
	  	throw (LineException("wrong date format (line: " + line + ")"));
      if (day == 29 and ((year % 100) % 4 != 0))
	  	throw (LineException("wrong date format (line: " + line + ")"));
	}
}

void	BitcoinExchange::isvalidFloat(std::string subline) const
{
	bool	dot = false;
	
	for (unsigned int i = 0; i < subline.size(); i++)
	{
		if (subline[i] == '.' && dot == false)
			dot = true;
		else if (isdigit(subline[i]) == false)
			throw (LineException("wrong float format (float: " + subline + ")"));
	}
}

void	BitcoinExchange::isvalidMult(std::string subline) const
{
	bool	dot = false;
	
	if (static_cast<long long>(strtod(subline.c_str(), NULL)) 
		!= static_cast<int>(strtod(subline.c_str(), NULL)))
		throw (LineException("int overflow (multiplier: " + subline + ")"));
	if (atof(subline.c_str()) > 1000)
		throw (LineException("multiplier too big (multiplier: " + subline + ")"));
	for (unsigned int i = 0; i < subline.size(); i++)
	{
		if (subline[i] == '.' && dot == false)
			dot = true;
		else if (isdigit(subline[i]) == false)
			throw (LineException("wrong multiplier format (multiplier: " + subline + ")"));
	}
}

void	BitcoinExchange::isvalidLine(std::string line, std::string sep,
	void (BitcoinExchange::*fun)(std::string line) const) const
{
	if (line.size() < 11 + sep.size())
		throw (LineException("wrong line format (line: " + line + ")"));
	isvalidDate(line, sep);
	(this->*fun)(line.substr(10 + sep.size()));
}

void	BitcoinExchange::isunique(std::string line) const
{
	std::map<std::string, float>::iterator	it;
	std::map<std::string, float>::iterator	ite = const_cast<BitcoinExchange *>(this)->end();
	for (it = const_cast<BitcoinExchange *>(this)->begin(); it != ite; it++)
	{
		if (it->first == line.substr(0, 10))
			throw (LineException("date already exists (line: " + line + ")"));
	}
}

void	BitcoinExchange::add_line(std::string line)
{
	try
	{
		isvalidLine(line, ",", &BitcoinExchange::isvalidFloat);
		isunique(line);
		std::string	key(line.substr(0, 10));
		float		value = static_cast<float>(atof(line.substr(11, line.size()).c_str()));
		(*this)[key] = value;
	}
	catch(const LineException& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	BitcoinExchange::loadDB(const std::string file)
{
	std::ifstream	ifs;
	std::string		buffer;
	ifs.open(file, std::ios::in);
	if (ifs.fail())
		throw (OpenFailureException());
	ifs.ignore(256, '\n');//number??
	while (!ifs.eof())
	{
		getline(ifs, buffer);
		if (buffer.empty() == false)
			add_line(buffer);
		buffer.erase();
	}
	ifs.close();
}

std::map<std::string, float>::iterator	BitcoinExchange::previous_date(std::string key) const
{
	std::map<std::string, float>::iterator	it;
	std::map<std::string, float>::iterator	ite = const_cast<BitcoinExchange *>(this)->begin()--;
	for (it = const_cast<BitcoinExchange *>(this)->end()--; it != ite; it--)
	{
		if (key >= it->first)
			break ;
	}
	if (it == ite)
		throw (LineException("no previous date to compare with (date: " + key + ")"));
	return (it);
}

void	BitcoinExchange::display_line(std::string line)
{
	
	try
	{
		isvalidLine(line, " | ", &BitcoinExchange::isvalidMult);
		std::map<std::string, float>::iterator	it = this->previous_date(line.substr(0, 10));
		float									mult = static_cast<float>(atof(line.substr(13).c_str()));
		std::cout << "Date used: " << it->first << " | Value: " << it->second
			<< " | Multiplier: " << mult << " | Final value: " << it->second * mult << std::endl;
	}
	catch(const LineException& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
}

void	BitcoinExchange::display(const std::string file)
{
	std::ifstream	ifs;
	std::string		buffer;
	ifs.open(file, std::ios::in);
	if (ifs.fail())
		throw (OpenFailureException());
	ifs.ignore(256, '\n');//number??
	while (!ifs.eof())
	{
		getline(ifs, buffer);
		if (buffer.empty() == false)
			display_line(buffer);
		buffer.erase();
	}
	ifs.close();
}

const char	*BitcoinExchange::OpenFailureException::what(void) const throw()
{
	return ("Failed to open file");
}

BitcoinExchange::LineException::LineException(const std::string str):
_str("Line error: " + str)
{
	return ;
}

BitcoinExchange::LineException::~LineException(void) throw()
{
	return ;
}

const char	*BitcoinExchange::LineException::what(void) const throw()
{
	return (this->_str.c_str());
}
