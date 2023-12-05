/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:47:04 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/05 10:32:33 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename A>
void	iter(A *array, size_t size, void (*function)(A &element))
{
	for (size_t i = 0; i < size; i++)
		function(array[i]);
}

#endif
