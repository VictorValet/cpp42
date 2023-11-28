/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:59:42 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/28 11:31:26 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	test1("BigBoss", 1);
	Bureaucrat	test2("DumbHead", 150);
	Intern		john;
	AForm		*form;
	
	try
	{
		form = john.makeForm("unexisting", "vvalet");
		form = john.makeForm("presidential pardon", "vvalet");
		test1.signForm(*form);
		test1.executeForm(*form);
		delete form;
		form = john.makeForm("robotomy request", "patient0");
		test1.signForm(*form);
		test1.executeForm(*form);
		delete form;
		form = john.makeForm("shrubbery creation", "42");
		test1.signForm(*form);
		test1.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
