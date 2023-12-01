/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:52:10 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/01 10:35:49 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(void)
{	
	ScalarConverter::convert("\'0\'");
	std::cout << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;
	ScalarConverter::convert("20");
	std::cout << std::endl;
	ScalarConverter::convert("33.32");
	std::cout << std::endl;
	ScalarConverter::convert("21456.32949494");
	std::cout << std::endl;
	ScalarConverter::convert("21456.32949494f");
}
