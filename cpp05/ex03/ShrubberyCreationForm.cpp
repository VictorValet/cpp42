/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:03:44 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/28 10:24:33 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
AForm("ShrubberyCreationForm", 145, 137)
{
	this->setTarget("No Target");
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string new_target):
AForm("ShrubberyCreationForm", 145, 137)
{
	this->setTarget(new_target);
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original):
AForm(original.getName(), original.getSignGrade(), original.getExecGrade())
{
	*this = original;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original)
{
	this->setTarget(original.getTarget());
	return (*this);
}

static void	draw_tree(std::ofstream &file, int width, int symbol)
{
	int	chars;
	int	i;
	
	chars = 1;
	i = 1;
	while (chars < width)
	{
		if (i % width == 0 && i != 0)
		{
			file.put('\n');
			if ((i / width) % 7 == 0)				
				chars -= 4;
			else
				chars += 2;
		}
		else if ((i % width) >= (width / 2 - chars / 2)
			&& (i % width) <= (width / 2 + chars / 2))
			file.put(symbol);
		else
			file.put(' ');
		i++;
	}
}

static void	draw_foot(std::ofstream &file, int width, int symbol)
{
	int	i;
	
	i = 1;
	while (i / width < width / 10)
	{
		if (i % width == 0 && i != 0)
			file.put('\n');
		else if ((i % width) > (width / 2) - (width / 10) 
			&& (i % width) < (width / 2) + (width / 10))
			file.put(symbol);
		else
			file.put(' ');
		i++;
	}
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string	new_file(this->getTarget() + "_shruberry");
	int			width;
	int			symbol;

	this->checkRequirements(executor);
	std::ofstream	file(new_file.c_str(), std::ios::out | std::ios::trunc);
	srand(time(NULL));
	width = (rand() % 40) + 10;
	symbol = (rand() % 4) + 35;
	draw_tree(file, width, symbol);
	draw_foot(file, width, symbol);
	file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}
