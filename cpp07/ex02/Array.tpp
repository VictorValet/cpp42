/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:03:05 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/05 16:44:29 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array(void)
{
	this->_size = 0;
	this->_array = new T[0];
	return ;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	this->_size = n;
	this->_array = new T[n];
	return ;
}

template<typename T>
Array<T>::Array(const Array &original)
{
	this->_size	= original.size();
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		(*this)[i] = original[i];
	return ;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array &original)
{
	if (this == &original)
		return (*this);
	delete[] this->_array;
	this->_size	= original.size();
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		(*this)[i] = original[i];
	return (*this);
}

template<typename T>
Array<T>::~Array(void)
{
	delete[] this->_array;
	return ;
}

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}

template<typename T>
T	&Array<T>::operator[](unsigned int n) const
{
	if (n >= this->_size)
	{
		throw (std::exception());
	}	
	return (this->_array[n]);
}
