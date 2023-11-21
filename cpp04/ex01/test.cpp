/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:11:40 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/21 15:31:31 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	Cat	*a = new Cat();
	Cat *b = new Cat(*a);
	Dog	*c = new Dog();
	a->setIdea(0, "Take over the world");
	a->setIdea(1, "Scratch human");
	b->setIdea(1, "Bite that finger");
	c->setIdea(0, "Bark at cats");
	Cat *d = new Cat(*a);
	a->setIdea(0, "");
	std::cout << "Cat a idea[0]: " << a->getIdea(0) << std::endl;
	std::cout << "Cat a idea[1]: " << a->getIdea(1) << std::endl;
	std::cout << "Dog b idea[0]: " << b->getIdea(0) << std::endl;
	std::cout << "Dog b idea[1]: " << b->getIdea(1) << std::endl;
	std::cout << "Cat c idea[0]: " << c->getIdea(0) << std::endl;
	std::cout << "Cat c idea[1]: " << c->getIdea(1) << std::endl;
	std::cout << "Cat d idea[0]: " << d->getIdea(0) << std::endl;
	std::cout << "Cat d idea[1]: " << d->getIdea(1) << std::endl;
	delete a;
	delete b;
	delete c;
	delete d;
	std::cout << std::endl;
	
	Animal *animals[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Animal[" << i << "] : "; 
		animals[i]->makeSound();
	}
	for (int i = 0; i < 10; i++)
		delete animals[i];
	return (0);
}
