/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:59:42 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/19 10:59:29 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <stdlib.h>
#include "Bureaucrat.hpp"

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

static std::string	prompt_name(std::string prompt)
{
	std::string str;

	while (1)
	{
		std::cout << prompt;
		if (getline(std::cin, str) == 0)
		{
			std::cout << std::endl;
			exit(0);
		}
		if (str != "\0")
			break ;
	}
	return(str);
}

static int	prompt_grade(std::string prompt)
{
	std::string str;
	
	while (1)
	{
		std::cout << prompt;
		if (getline(std::cin, str) == 0)
		{
			std::cout << std::endl;
			exit(0);
		}
		if (str != "\0" && is_int(str) == true)
			break ;
	}
	return(atoi(str.c_str()));
}

int	main(void)
{
	Bureaucrat	noname;
	std::string	name;
	int			grade;
	
	std::cout << noname;
	name = prompt_name("Insert name of bureaucrat: ");
	grade = prompt_grade("Insert grade of bureaucrat: ");
	try
	{
		Bureaucrat tester(name, grade);
		std::cout << tester;
		std::cout << "Ascending grade by 1\n";
		tester.higherGrade();
		std::cout << tester;
		std::cout << "Descending grade by 2\n";
		tester.lowerGrade();
		tester.lowerGrade();
		std::cout << tester;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
