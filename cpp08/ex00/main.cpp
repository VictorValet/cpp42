/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:45:32 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/15 11:22:07 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <deque>
#include <list>
#include <vector>

int main(void)
{
	int					searched = 12;
	int					size = 20;
	std::list<int>		l;
	std::deque<int>		d;
	std::vector<int>	v(size);

	for (int i = 0; i < size; i++)
	{
		l.push_back(i);
		d.push_back(i * 2);
		v[i] = i * 3;
	}

	try
	{
		std::cout << &easyfind(v, searched) << " : " << easyfind(v, searched) << std::endl;
		std::cout << &easyfind(d, searched) << " : " << easyfind(d, searched) << std::endl;
		std::cout << &easyfind(l, searched) << " : " << easyfind(l, searched) << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
