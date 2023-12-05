/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:52:10 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/04 16:34:19 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void	add_2(T &x)
{
	x += 2;
}

int main(void)
{
	int		test_int[] = {0, 1, 2, 3, 4, 5, 6};
	float	test_float[] = {0, 1, 2, 3, 4, 5, 6};
	char	test_char[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

	iter(test_int, 7, add_2);
	for (int i = 0; i < 7; i++)
		std::cout << "test_int[" << i << "] = " << test_int[i] << std::endl;
	iter(test_float, 7, add_2);
	for (int i = 0; i < 7; i++)
		std::cout << "test_float[" << i << "] = " << test_float[i] << std::endl;
	iter(test_char, 7, add_2);
	for (int i = 0; i < 7; i++)
		std::cout << "test_char[" << i << "] = " << test_char[i] << std::endl;
}
