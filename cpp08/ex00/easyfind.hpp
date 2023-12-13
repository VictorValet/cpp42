/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:42:57 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/13 12:33:02 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iterator>
#include <algorithm>

template<typename T>
int	&easyfind(T cont, int i)
{
	typename T::iterator found = std::find(cont.begin(), cont.end(), i);
	if (found != cont.end())
		return (*found);
	throw (std::exception());
}

#endif
