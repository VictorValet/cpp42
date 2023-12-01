/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:59:44 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/01 10:20:40 by vvalet           ###   ########.fr       */
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

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't sign " << f.getName() << " because ";
		if (f.getSigned() == true)
			std::cout << "it was already signed." << std::endl;
		else
			std::cout << "his grade is " << this->_grade << " and a grade " << f.getSignGrade()
			<< " is required."  << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &f) const
{
	try
	{
		f.execute(*this);
		std::cout << this->_name << " executed " << f.getName() << std::endl; 
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't execute " << f.getName() << " because ";
		if (f.getSigned() == false)
			std::cout << "it wasn't signed." << std::endl;
		else
			std::cout << "his grade is " << this->_grade << " and a grade " << f.getExecGrade()
			<< " is required."  << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat Exception: Grade is too high.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat Exception: Grade is too low.");
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return (o);
}
