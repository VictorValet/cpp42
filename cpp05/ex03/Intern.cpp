/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:48:39 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/29 14:18:55 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	return ;
}

Intern::Intern(const Intern &original)
{
	(void) original;
	return ;
}

Intern	&Intern::operator=(const Intern &original)
{
	(void) original;
	return (*this);
}

Intern::~Intern(void)
{
	return ;
}

static AForm	*makeShrubberyCreation(std::string new_target)
{
	return (new ShrubberyCreationForm(new_target));
}

static AForm	*makeRobotomyRequest(std::string new_target)
{
	return (new RobotomyRequestForm(new_target));
}

static AForm	*makePresidentialPardon(std::string new_target)
{
	return (new PresidentialPardonForm(new_target));
}

AForm	*Intern::makeForm(std::string name, std::string new_target)
{
	std::string	names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm		*(*fct[3])(std::string) = {makeShrubberyCreation, makeRobotomyRequest, makePresidentialPardon};
	AForm		*form;

	form = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (names[i].compare(name) == 0)//a changer
		{
			std::cout << "Intern creates " << name << std::endl;
			form = fct[i](new_target);
			break ;
		}
		if (i == 2)
			std::cout << "No match found, NULL ptr returned" << std::endl;
	}
	return (form);
}
