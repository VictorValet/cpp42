/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:48:19 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/21 17:11:34 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	AMateria		*sort1 = new Ice;
	AMateria		*sort2 = (Ice *)sort1->clone();
	AMateria		*sort3 = new Cure;
	AMateria		*sort4 = (Cure *)sort3->clone();
	MateriaSource	source;
	Character		c1("Anton");
	Character		c2("Ben");
	const AMateria	*to_delete;

	std::cout << "Sort1 (" << sort1 << ") : " << sort1->getType() << std::endl;
	std::cout << "Sort2 (" << sort2 << ") : " << sort2->getType() << std::endl;
	std::cout << "Sort3 (" << sort3 << ") : " << sort3->getType() << std::endl;
	std::cout << "Sort4 (" << sort4 << ") : " << sort4->getType() << std::endl;
	source.learnMateria(sort1);
	source.learnMateria(sort2);
	source.learnMateria(sort3);
	source.learnMateria(sort4);
	std::cout << "source1 (" << source.getKnown(0) << ") : " << source.getKnown(0)->getType() << std::endl;
	std::cout << "source2 (" << source.getKnown(1) << ") : " << source.getKnown(1)->getType() << std::endl;
	std::cout << "source3 (" << source.getKnown(2) << ") : " << source.getKnown(2)->getType() << std::endl;
	std::cout << "source4 (" << source.getKnown(3) << ") : " << source.getKnown(3)->getType() << std::endl;
	c1.equip(source.createMateria("test"));
	c1.equip(source.createMateria("ice"));
	c1.equip(source.createMateria("ice"));
	c2 = c1;
	c1.equip(source.createMateria("cure"));
	c1.equip(source.createMateria("cure"));
	std::cout << "c1.inventory1 (" << c1.getInventory(0) << ") : " << c1.getInventory(0)->getType() << std::endl;
	std::cout << "c1.inventory2 (" << c1.getInventory(1) << ") : " << c1.getInventory(1)->getType() << std::endl;
	std::cout << "c1.inventory3 (" << c1.getInventory(2) << ") : " << c1.getInventory(2)->getType() << std::endl;
	std::cout << "c1.inventory4 (" << c1.getInventory(3) << ") : " << c1.getInventory(3)->getType() << std::endl;
	std::cout << "c2.inventory1 (" << c2.getInventory(0) << ") : " << c2.getInventory(0)->getType() << std::endl;
	std::cout << "c2.inventory2 (" << c2.getInventory(1) << ") : " << c2.getInventory(1)->getType() << std::endl;
	c1.use(0, c2);
	c1.use(2, c2);
	to_delete = c1.getInventory(1);
	c1.unequip(1);
	delete to_delete;
	c1.use(1, c2);

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return (0);
}
