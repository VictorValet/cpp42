/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:56:42 by vvalet            #+#    #+#             */
/*   Updated: 2023/10/30 16:09:59 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string &stringREF = str;

	std::cout 	<< "Adress via variable: " << &str << std::endl
				<< "Adress via pointer: " << stringPTR << std::endl
				<< "Adress via reference: " << &stringREF << std::endl
				<< "Value via variable: " << str << std::endl
				<< "Value via pointer: " << *stringPTR << std::endl
				<< "Value via reference: " << stringREF << std::endl;	
}
