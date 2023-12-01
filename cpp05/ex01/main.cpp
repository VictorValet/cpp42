/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:59:42 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/01 10:28:23 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <stdlib.h>
#include "Bureaucrat.hpp"

static std::string	prompt_name(std::string prompt)
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

static int	prompt_grade(std::string prompt)
{
	std::string str;
	
	while (1)
	{
		std::cout << prompt;
		getline(std::cin, str);
		if (str.compare("\0") != 0
			&& atoll(str.c_str()) <= INT_MAX 
			&& atoll(str.c_str()) >= INT_MIN)
			break ;
	}
	return(atoi(str.c_str()));
}

int	main(void)
{
	Bureaucrat	test1("BigBoss", 1);
	Bureaucrat	test2("DumbHead", 150);
	std::string	name;
	int			sign_grade;
	int			exec_grade;
	
	name = prompt_name("Insert name of form: ");
	sign_grade = prompt_grade("Insert signing requirement of form: ");
	exec_grade = prompt_grade("Insert executing requirement of form: ");
	try
	{
		Form f(name, sign_grade, exec_grade);
		std::cout << f;
		test2.signForm(f);
		test1.signForm(f);
		test2.signForm(f);
		test1.signForm(f);
		std::cout << f;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
