/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:37:37 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/27 10:08:58 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void):
_name("noname"),
_signed(false),
_sign_grade(150),
_exec_grade(150)
{
	return ;
}

AForm::AForm(const std::string name, int sign_grade, int exec_grade):
_name(name),
_signed(false),
_sign_grade(sign_grade),
_exec_grade(exec_grade)
{
	if (this->_sign_grade > 150 || this->_exec_grade > 150)
		throw (GradeTooLowException());
	if (this->_sign_grade < 1 || this->_exec_grade < 1)
		throw (GradeTooHighException());
	return ;
}

AForm::AForm(const AForm &original):
_name("noname"),
_signed(false),
_sign_grade(original.getSignGrade()),
_exec_grade(original.getExecGrade())
{
	return ;
}

AForm	&AForm::operator=(const AForm &original)
{
	(void) original;
	return (*this);
}

AForm::~AForm(void)
{
	return ;
}

std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getSignGrade() const
{
	return (this->_sign_grade);
}

int	AForm::getExecGrade() const
{
	return (this->_exec_grade);
}

std::string	AForm::getTarget() const
{
	return (this->_target);
}

void	AForm::setTarget(std::string new_target)
{
	this->_target = new_target;
}

void	AForm::beSigned(Bureaucrat b)
{
	if (this->_signed == false && b.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw(GradeTooLowException());
}

void	AForm::checkRequirements(Bureaucrat b) const
{
	if (this->_signed == false)
		throw (AForm::UnsignedException());
	else if (b.getGrade() > this->_exec_grade)
		throw (AForm::GradeTooLowException());
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("AForm Exception: Grade is too high.");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("AForm Exception: Grade is too low.");
}

const char	*AForm::AlreadySignedException::what() const throw()
{
	return ("AForm Exception: AForm is already signed.");
}

const char	*AForm::UnsignedException::what() const throw()
{
	return ("AForm Exception: AForm is not signed.");
}

std::ostream	&operator<<(std::ostream &o, AForm &f)
{
	if (f.getSigned() == true)
		o << "AForm " << f.getName() << " is signed." << std::endl;
	if (f.getSigned() == false)
		o << "AForm " << f.getName() << " is not signed." << std::endl;
	o << "It requires a grade " << f.getSignGrade() << " to be signed." << std::endl;
	o << "It requires a grade " << f.getExecGrade() << " to be executed." << std::endl;
	return (o);
}
