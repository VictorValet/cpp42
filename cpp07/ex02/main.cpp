/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:22:44 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/11 10:21:14 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main(void)
{
	//empty array
	try
	{
		Array<int>	empty;
		std::cout << &empty << " : " << empty.size() << std::endl;
		std::cout << empty[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	//working array
	try
	{
		Array<int>	array(5);
		for (unsigned int i = 0; i < array.size(); i++)
			array[i] = i;
		Array<int>	array_copy(array);
		for (unsigned int i = 0; i < array_copy.size(); i++)
			array_copy[i] *= 2;
		for (unsigned int i = 0; i < array.size(); i++)
		{
			std::cout << "array [" << i << "] : " << array[i] << " | ";
			std::cout << "array_copy [" << i << "] : " << array_copy[i] << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	//array with randomized numbers
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	//assignment operator and copy constructor
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	//copied values
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
		std::cerr << "didn't save the same value!!" << std::endl;
		return 1;
		}
	}

	//out of bounds with subscript operator
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//assignment with subscript operator
	for (unsigned int i = 0; i < numbers.size() / 100; i++)
			std::cout << "numbers[" << i << "] : " << numbers[i] << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = rand();
	for (unsigned int i = 0; i < numbers.size() / 100; i++)
		std::cout << "numbers[" << i << "] : " << numbers[i] << std::endl;
	
	delete [] mirror;
	return 0;
}
