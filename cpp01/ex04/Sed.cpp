/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:00:29 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/19 10:58:42 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <iostream>

Sed::Sed(char const *file, char const *s, char const *r):
searched(s),
replacer(r),
state(0)
{
	std::string	new_file(file);
	
	new_file += ".replace";
	this->infile.open(file, std::ios::in);
	if (this->infile.fail() == 1)
	{
		std::cerr	<< "File error: " << file 
					<< ": ifstream error\n";
		this->state = 1;
		return ;
	}
	this->outfile.open(new_file, std::ios::out);
	if (this->outfile.fail() == 1)
	{
		std::cerr	<< "File error: " << new_file 
					<< ": ofstream error\n";
		this->state = 1;
	}
}

Sed::~Sed(void)
{
	return ;
}

bool	Sed::replace(void)
{
	char	c;
	int		pos;

	if (this->state == 1)
		return (1);
	while (this->infile.get(c))
		this->buffer.push_back(c);
	pos = 0;
	while (pos + this->searched.length() <= this->buffer.length()
		&& this->searched != this->replacer
		&& this->buffer.find(this->searched, pos) != std::string::npos)
	{
		pos = this->buffer.find(this->searched, pos);
		this->buffer.erase(pos, this->searched.length());
		this->buffer.insert(pos, this->replacer);
		pos += this->replacer.length();
	}
	this->outfile << buffer;
	return (0);
}
