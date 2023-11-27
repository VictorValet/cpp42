/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:06:38 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/27 12:39:56 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
AForm("RobotomyRequestForm", 72, 45)
{
	this->setTarget("No Target");
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string new_target):
AForm("RobotomyRequestForm", 72, 45)
{
	this->setTarget(new_target);
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original):
AForm(original.getName(), original.getSignGrade(), original.getExecGrade())
{
	*this = original;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &original)
{
	this->setTarget(original.getTarget());
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->checkRequirements(executor);
	std::cout << "Bip Bop Bop Bzzz RRRR Bzzzttt..." << std::endl;
	srand (time(NULL));
	if (rand() % 2 == 1)
		std::cout << "We inform you that " << this->getTarget()
		<< " has been robotomized succesfuly! " << std::endl;
	else
		std::cout << "We inform you that " << this->getTarget()
		<< " has unexpectedly and tragically die of an unsuccesful robotomy. Have a nice day! " << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}
