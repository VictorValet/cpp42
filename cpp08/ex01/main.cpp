/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:45:32 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/12 12:08:01 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void)
{
	Span	tester(30000);
	try
	{
		unsigned int n;
		n = tester.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	for(unsigned int i = 0; i < tester.getMax(); i++)
		tester.addNumber(i);
	std::cout << "Longest span is " << tester.longestSpan() << std::endl;
	std::cout << "Shortest span is " << tester.shortestSpan() << std::endl;
	tester.fillNumbers(tester.begin(), tester.end());
	std::cout << "Longest span is " << tester.longestSpan() << std::endl;
	std::cout << "Shortest span is " << tester.shortestSpan() << std::endl;
	
	// Span sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	// return 0;
}
