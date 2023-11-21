/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:11:40 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/16 13:34:36 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrongmeta = new WrongCat();
	std::cout << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << wrongmeta->getType() << " " << std::endl;
	std::cout << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	wrongmeta->makeSound();
	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrongmeta;
	return (0);
}
