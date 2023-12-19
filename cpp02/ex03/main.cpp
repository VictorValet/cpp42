/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:02:39 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/19 10:59:20 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iomanip>
#include <iostream>

static int	prompt_float(std::string prompt, float *value)
{
	std::string str;
	
	while (1)
	{
		std::cout << prompt;
		getline(std::cin, str);
		if (str == "exit")
			return (1);
		try
		{
			std::stof(str);
			break ;
		}
		catch(const std::exception &e)
		{
			std::cout << "Please insert a floating point value" << std::endl;
		}
	}
	*value = atof(str.c_str());
	return(0);
}

static int	update_values(float values[8])
{
	if (prompt_float("v_a x (float): ", &values[0]) == 0
		&& prompt_float("v_a y (float): ", &values[1]) == 0
		&& prompt_float("v_b x (float): ", &values[2]) == 0
		&& prompt_float("v_b y (float): ", &values[3]) == 0
		&& prompt_float("v_c x (float): ", &values[4]) == 0
		&& prompt_float("v_c y (float): ", &values[5]) == 0
		&& prompt_float("p x (float): ", &values[6]) == 0
		&& prompt_float("p y (float): ", &values[7]) == 0)
		return (0);
	return (1);
}

int main(void) 
{
	float	values[8];

	while (1)
	{
		if (update_values(values) == 1)
			break ;
		Point 		v_a(values[0], values[1]);
		Point 		v_b(values[2], values[3]);
		Point 		v_c(values[4], values[5]);
		Point 		p(values[6], values[7]);
		std::cout << "v_a: " << v_a << std::endl;
		std::cout << "v_b: " << v_b << std::endl;
		std::cout << "v_c: " << v_c << std::endl;
		std::cout << "p: " << p << std::endl;
		if (bsp(v_a, v_b, v_c, p) == true)
			std::cout << "POINT IS IN TRIANGLE\n";
		else
			std::cout << "POINT IS NOT IN TRIANGLE\n";
	}
	exit(0);
}
