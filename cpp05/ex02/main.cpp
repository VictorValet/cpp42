/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:59:42 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/27 16:19:29 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	Bureaucrat	test1("BigBoss", 1);
	Bureaucrat	test2("DumbHead", 150);
	ShrubberyCreationForm f1("42");
	PresidentialPardonForm f2("patient0");
	RobotomyRequestForm f3("vvalet");
	
	try
	{
		test1.executeForm(f1);
		test2.signForm(f1);
		test1.signForm(f1);
		test1.signForm(f2);
		test1.signForm(f3);
		test2.executeForm(f1);
		test1.executeForm(f1);
		test1.executeForm(f2);
		test1.executeForm(f3);
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
