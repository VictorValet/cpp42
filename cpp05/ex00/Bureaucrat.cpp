/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:59:44 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/27 09:53:17 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):
_name("noname"),
_grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade):
_name(name),
_grade(grade)
{
	if (this->_grade > 150)
		throw (GradeTooLowException());
	if (this->_grade < 1)
		throw (GradeTooHighException());
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &original):
_name("noname")
{
	*this = original;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &original)
{
	this->_grade = original.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	return ;
}

const std::string	Bureaucrat::getName() const
{
	return(this->_name);
}

int	Bureaucrat::getGrade() const
{
	return(this->_grade);
}

void	Bureaucrat::higherGrade()
{
	if (this->_grade == 1)
		throw (GradeTooHighException());
	else
		this->_grade--;
}

void	Bureaucrat::lowerGrade()
{
	if (this->_grade == 150)
		throw (GradeTooLowException());
	else
		this->_grade++;
}

const char	*Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Grade is too high.");
}

const char	*Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Grade is too low.");
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return (o);
}