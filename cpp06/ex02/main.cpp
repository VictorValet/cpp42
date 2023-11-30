/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:52:10 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/30 16:19:33 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	Base	tester;
	Base	&ref = *tester.generate();
	Base	*ptr = &ref;

	tester.identify(ref);
	tester.identify(ptr);

	delete ptr;
}
