/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:52:10 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/30 16:11:09 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data		*ptr1;
	Data		*ptr2;
	
	ptr1 = new Data(5);
	std::cout << "ptr1: " << ptr1 << std::endl;
	std::cout << "ptr2: " << ptr2 << std::endl;
	ptr2 = Serializer::deserialize(Serializer::serialize(ptr1));
	std::cout << "ptr1: " << ptr1 << std::endl;
	std::cout << "ptr2: " << ptr2 << std::endl;

	delete ptr1;
}
