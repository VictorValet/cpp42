/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:45:48 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/30 14:53:42 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <iostream>

class Serializer
{
	public:
		~Serializer(void);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	protected:
		Serializer(void);
		Serializer(const Serializer &original);
		Serializer	&operator=(const Serializer &original);
};

#endif
