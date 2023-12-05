/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:30:26 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/05 11:22:19 by vvalet           ###   ########.fr       */
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
		Array(Array &original);
		Array &operator=(Array &original);
		~Array(void);
		unsigned int	size(void) const;
		
	private:
		T				*_element;
		unsigned int	_size;
};

#endif
