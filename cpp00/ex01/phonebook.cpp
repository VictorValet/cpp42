/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:52:15 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/19 10:57:43 by vvalet           ###   ########.fr       */
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
		if (str != "\0")
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
		if (str != "\0"
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
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
	}
	return (0);	
}
