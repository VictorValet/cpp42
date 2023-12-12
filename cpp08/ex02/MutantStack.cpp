/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:25:01 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/12 12:25:02 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

MutantStack::MutantStack(void)
{
	return ;
}

MutantStack::MutantStack(const MutantStack &original)
{
	*this = original;
	return ;
}

MutantStack	&MutantStack::operator=(const MutantStack &original)
{
	return (*this);
}

MutantStack::~MutantStack(void)
{
	return ;
}
