/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:02:43 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/05 14:57:28 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &original);
		Array	&operator=(const Array &original);
		~Array(void);
		unsigned int	size(void) const;
		T				&operator[](unsigned int n) const;

	private:
		T				*_array;
		unsigned int	_size;
};

#include "Array.tpp"

#endif
