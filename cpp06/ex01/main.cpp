/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:52:10 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/01 10:46:21 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data		*ptr1;
	Data		*ptr2;
	Data		*ptr3;
	
	ptr1 = new Data(5);
	ptr2 = new Data(10);
	ptr3 = ptr2;
	std::cout << "ptr1: " << ptr1 << " | value: " << ptr1->getI() << std::endl;
	std::cout << "ptr2: " << ptr2 << " | value: " << ptr2->getI() << std::endl;
	ptr2 = Serializer::deserialize(Serializer::serialize(ptr1));
	std::cout << "ptr1: " << ptr1 << " | value: " << ptr1->getI() << std::endl;
	std::cout << "ptr2: " << ptr2 << " | value: " << ptr2->getI() << std::endl;

	delete ptr1;
	delete ptr3;
}
