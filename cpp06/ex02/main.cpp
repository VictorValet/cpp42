/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:52:10 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/11 15:30:27 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cstdlib>
# include <ctime>
# include <iostream>
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base	*generate(void)
{
	srand (time(NULL));
	int	i = rand();
	if (i % 3 == 0)
		return (static_cast<Base *>(new A()));
	if (i % 3 == 1)
		return (static_cast<Base *>(new B()));
	else
		return (static_cast<Base *>(new C()));
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != 0)
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p) != 0)
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p) != 0)
		std::cout << "C\n";
}

void	identify(Base &p)
{
	Base	&ref = p;
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

int main(void)
{
	Base	*ptr = generate();
	Base	&ref = *ptr;

	identify(ref);
	identify(ptr);

	delete ptr;
}
