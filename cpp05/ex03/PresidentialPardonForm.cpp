/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:09:08 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/27 12:13:50 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
AForm("PresidentialPardonForm", 25, 5)
{
	this->setTarget("No Target");
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string new_target):
AForm("PresidentialPardonForm", 25, 5)
{
	this->setTarget(new_target);
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original):
AForm(original.getName(), original.getSignGrade(), original.getExecGrade())
{
	*this = original;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &original)
{
	this->setTarget(original.getTarget());
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->checkRequirements(executor);
	std::cout << "We inform you that " << this->getTarget()
	<< " has been pardoned by president Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}
