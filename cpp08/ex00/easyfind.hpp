/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:42:57 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/11 16:08:36 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iterator>

template<typename T>
int	&easyfind(T cont, int i)
{
	typename T::iterator it;
	typename T::iterator ite = cont.end();
	for (it = cont.begin(); it != ite; ++it)
	{
		if (*it == i)
			return (*it);
	}
	throw (std::exception());
}

#endif
