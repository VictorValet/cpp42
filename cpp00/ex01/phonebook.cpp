/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:52:15 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/21 16:21:40 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "PhoneBook.class.hpp"

std::string	prompt_info(std::string prompt)
{
	std::string str;

	while (1)
	{
		std::cout << prompt;
		getline(std::cin, str);
		if (str.compare("\0") != 0)
			break ;
	}
	return(str);
}

std::string	prompt_numbers(std::string prompt)
{
	std::string str;
	
	while (1)
	{
		std::cout << prompt;
		getline(std::cin, str);
		if (str.compare("\0") != 0
			&& all_of(str.begin(), str.end(), isdigit) == 1)
			break ;
	}
	return(str);
}

int	main(void)
{
	PhoneBook 	phonebook;
	std::string	command;
	
	while (1)
	{
		command = prompt_info("Please type ADD, SEARCH or EXIT: ");
		if (command.compare("EXIT") == 0)
			break ;
		else if (command.compare("ADD") == 0)
			phonebook.add();
		else if (command.compare("SEARCH") == 0)
			phonebook.search();
	}
	return (0);	
}
