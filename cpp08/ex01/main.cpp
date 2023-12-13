/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:45:32 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/12 14:57:48 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

#define TEST_VALUE 30000

int main(void)
{
	Span				tester(TEST_VALUE);
	std::vector<int>	filler;
	try
	{
		tester.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		/* Fill the filler with random numbers */
		srand(time(NULL));
		for(unsigned int i = 0; i < TEST_VALUE; i++)
			filler.push_back(rand());

		/* Fill the tester with filler numbers */
		tester.addNumbers(filler.begin(), filler.end());

		/* Print the Span */
		// std::cout << tester << "Span printer end\n";

		/* Test spans */
		std::cout << "Longest span is " << tester.longestSpan() << std::endl;
		std::cout << "Shortest span is " << tester.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
