/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:52:13 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/21 16:21:37 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void): _saved(0)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::getfirstname(void) const
{
	return(this->first_name);
}

std::string	Contact::getlastname(void) const
{
	return(this->last_name);
}

std::string	Contact::getnickname(void) const
{
	return(this->nickname);
}

std::string	Contact::getphonenumber(void) const
{
	return(this->phone_number);
}

std::string	Contact::getdarkestsecret(void) const
{
	return(this->darkest_secret);
}

int			Contact::getsaved(void) const
{
	return(this->_saved);
}
void		Contact::complete_infos(void)
{
	this->first_name = prompt_info("First name: ");
	this->last_name = prompt_info("Last name: ");
	this->nickname = prompt_info("Nickname: ");
	this->phone_number = prompt_numbers("Phone number: ");
	this->darkest_secret = prompt_info("Darkest secret: ");
	this->_saved = 1;
}
