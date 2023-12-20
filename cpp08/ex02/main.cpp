/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:45:32 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/20 17:24:36 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main(void)
{
	//check canonical requirements
	{
		MutantStack< int, std::list<int> > 			test;
		MutantStack< float, std::vector<float> >	test_wrong;
		MutantStack< int, std::list<int> >			test_copy(test);
		std::cout << test_copy.size() << std::endl;
		test.push(5);
		test.push(10);
		test_copy = test;
		std::cout << test_copy.size() << std::endl;
	}

	//with MutantStack
	{
		MutantStack<int> mstack;
		mstack.push(84);
		mstack.push(7378);
		mstack.push(1);
		mstack.push(3);
		mstack.pop();
		mstack.push(45122);
		mstack.push(751);
		std::cout << "Last inserted number: " << mstack.top() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;
		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::const_iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "Element " << mstack.size() - std::distance(it, ite)
				<< " : " << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	
	// with std::list
	{
		std::list<int> mstack;
		mstack.push_back(84);
		mstack.push_back(7378);
		mstack.push_back(1);
		mstack.push_back(3);
		mstack.pop_back();
		mstack.push_back(45122);
		mstack.push_back(751);
		std::cout << "Last inserted number: " << mstack.back() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;
		std::list<int>::const_iterator it = mstack.begin();
		std::list<int>::const_iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "Element " << mstack.size() - std::distance(it, ite)
				<< " : " << *it << std::endl;
			++it;
		}
	}
}
