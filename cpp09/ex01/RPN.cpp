/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:59:28 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/18 16:41:45 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	return ;
}

RPN::RPN(char *str)
{
	process_string(std::string(str));
	return ;
}

RPN::RPN(const RPN &original)
{
	*this = original;
	return ;
}

RPN	&RPN::operator=(const RPN &original)
{
	(void) original;
	return (*this);
}

RPN::~RPN(void)
{
	return ;
}

void	RPN::validate_token(std::string tok) const
{
	if (tok.size() != 1 || (isdigit(tok[0]) == false 
		&& tok[0] != '+' && tok[0] != '-' && tok[0] != '*' && tok[0] != '/'))
		throw (WrongInputException("bad token"));
}

void	RPN::validate_operation(char op, int const &left_operand, int const &right_operand) const
{
	if (op == '/' && right_operand == 0)
		throw (WrongInputException("division by 0"));
	if ((op == '+' && left_operand > INT_MAX - right_operand)
		|| (op == '-' && left_operand < INT_MIN + right_operand)
		|| (op == '*' && left_operand == 0 && (left_operand > INT_MAX / right_operand
			|| left_operand < INT_MIN / right_operand)))
		throw (WrongInputException("overflow"));
}

void	RPN::make_operation(char op)
{
	if (this->size() < 2)
		throw (WrongInputException("not enough operands to execute operator"));
	int	right_operand = this->top();
	this->pop();
	int &left_operand = this->top();
	validate_operation(op, left_operand, right_operand);
	if (op == '+')
		left_operand += right_operand;
	else if (op == '-')
		left_operand -= right_operand;
	else if (op == '*')
		left_operand *= right_operand;
	else if (op == '/')
		left_operand /= right_operand;
}

void	RPN::process_string(std::string str)
{
	char *tok = strtok(const_cast<char *>(str.c_str()), " \t\n\v\f\r");
	while (tok != NULL)
	{
		validate_token(tok);
		if (isdigit(tok[0]) == true)
			this->push(atoi(tok));
		else
			this->make_operation(tok[0]);
		tok = strtok(NULL, " \t\n\v\f\r");
	}
	if (this->size() > 1)
		throw (WrongInputException("not enough operators to empty the stack"));
	std::cout << this->top() << std::endl;
	return ;
}

RPN::WrongInputException::WrongInputException(const std::string str):
_str("Wrong RPN expression: " + str)
{
	return ;
}

RPN::WrongInputException::~WrongInputException(void) throw()
{
	return ;
}

const char *RPN::WrongInputException::what(void) const throw()
{
	return (this->_str.c_str());
}
