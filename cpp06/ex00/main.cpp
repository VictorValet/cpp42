/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:52:10 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/30 14:37:17 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestClass.hpp"

int main(void)
{
	TestClass converter;
	
	converter.convert("\'0\'");
	converter.convert("0");
	converter.convert("20");
	converter.convert("33.32");
	converter.convert("21456.32949494");
	converter.convert("21456.32949494f");

	// converter.convert("2147483647");
	// converter.convert("-2147483648");
	// converter.convert("2147483648");
	// converter.convert("-2147483649");
	
}
