/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestClass.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:40:12 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/29 11:42:43 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestClass.hpp"

TestClass::TestClass(void)
{
	return ;
}

TestClass::TestClass(const TestClass &original)
{
	(void) original;
	return ;
}

TestClass	&TestClass::operator=(const TestClass &original)
{
	(void) original;
	return (*this);
}

TestClass::~TestClass(void)
{
	return ;
}
