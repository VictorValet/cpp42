/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:54:27 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/19 10:56:23 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void): _counter(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add(void)
{
	this->_contacts[_counter].complete_infos();
	if (this->_counter < 7)
		this->_counter++;
	else
		this->_counter = 0;
}

void	PhoneBook::search(void) const
{
	if (this->_contacts[0].getsaved() == 0)
	{
		std::cout << "Table is empty" << std::endl;
		return ;
	}
	_display_tab();
	_display_contact();
}

std::string	PhoneBook::_truncate(std::string str) const
{
	if (str.size() > 10)
		return (str.substr(0, 10).replace(9, 1, "."));
	else
		return (str);
}

void	PhoneBook::_display_tab(void) const
{
	int			i;
	std::string	str;
	
	i = 0;
	std::cout	<< "|----------|----------|----------|----------|" << std::endl
				<< "|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
				<< "|----------|----------|----------|----------|" << std::endl;
	while (i < 8)
	{
		if (this->_contacts[i].getsaved() == 0)
			break ;
		std::cout	<< "|" << std::setw(10) << i << "|"
					<< std::setw(10) << _truncate(this->_contacts[i].getfirstname()) << "|"
					<< std::setw(10) << _truncate(this->_contacts[i].getlastname()) << "|"
					<< std::setw(10) << _truncate(this->_contacts[i].getnickname()) << "|" << std::endl
					<< "|----------|----------|----------|----------|" << std::endl;
		i++;
	}
}

void	PhoneBook::_display_contact(void) const
{
	std::string	str;
	int			index;
	
	std::cout << "Index: ";
	getline(std::cin, str);
	if (all_of(str.begin(), str.end(), isdigit) != 1 || str == "\0")
	{
		std::cout << "Wrong input" << std::endl;
		return ;
	}
	else
		index = atoi(str.c_str());
	if (index < 0 || index > 7 || this->_contacts[index].getsaved() == 0)
	{
		std::cout << "Wrong index" << std::endl;
		return ;
	}
	else
	{
		std::cout	<< "First Name: " << this->_contacts[index].getfirstname() << std::endl
					<< "Last Name: " << this->_contacts[index].getlastname() << std::endl
					<< "Nickname: " << this->_contacts[index].getnickname() << std::endl
					<< "Phone Number: " << this->_contacts[index].getphonenumber() << std::endl
					<< "Darkest Secret: " << this->_contacts[index].getdarkestsecret() << std::endl;
	}
}
