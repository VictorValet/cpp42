/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:37:37 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/27 10:08:58 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void):
_name("noname"),
_signed(false),
_sign_grade(150),
_exec_grade(150)
{
	return ;
}

Form::Form(const std::string name, int sign_grade, int exec_grade):
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

Form::Form(const Form &original):
_name("noname"),
_signed(false),
_sign_grade(original.getSignGrade()),
_exec_grade(original.getExecGrade())
{
	return ;
}

Form	&Form::operator=(const Form &original)
{
	(void) original;
	return (*this);
}

Form::~Form(void)
{
	return ;
}

std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getSignGrade() const
{
	return (this->_sign_grade);
}

int	Form::getExecGrade() const
{
	return (this->_exec_grade);
}

void	Form::beSigned(Bureaucrat b)
{
	if (this->_signed == false && b.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw(GradeTooLowException());
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form Exception: Grade is too high.");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form Exception: Grade is too low.");
}

const char	*Form::AlreadySignedException::what() const throw()
{
	return ("Form Exception: Form is already signed.");
}

std::ostream	&operator<<(std::ostream &o, Form &f)
{
	if (f.getSigned() == true)
		o << "Form " << f.getName() << " is signed." << std::endl;
	if (f.getSigned() == false)
		o << "Form " << f.getName() << " is not signed." << std::endl;
	o << "It requires a grade " << f.getSignGrade() << " to be signed." << std::endl;
	o << "It requires a grade " << f.getExecGrade() << " to be executed." << std::endl;
	return (o);
}
