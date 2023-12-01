/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:36:58 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/01 10:51:12 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)
{
	return ;
}

Base	*Base::generate(void)
{
	srand (time(NULL));
	if (rand() % 3 == 0)
		return (static_cast<Base *>(new A()));
	if (rand() % 3 == 1)
		return (static_cast<Base *>(new B()));
	else
		return (static_cast<Base *>(new C()));
}

void	Base::identify(Base *p)
{
	if (dynamic_cast<A*>(p) != 0)
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p) != 0)
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p) != 0)
		std::cout << "C\n";
}

void	Base::identify(Base &p)
{
	Base	&ref = *this;
	try
	{
		ref = dynamic_cast<A&>(p);
		std::cout << "A\n";
	}
	catch(const std::exception &e){}
	try
	{
		ref = dynamic_cast<B&>(p);
		std::cout << "B\n";
	}
	catch(const std::exception &e){}
	try
	{
		ref = dynamic_cast<C&>(p);
		std::cout << "C\n";
	}
	catch(const std::exception &e){}	
}

