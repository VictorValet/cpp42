/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:25:11 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/30 16:19:57 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <cstdlib>
# include <ctime>
# include <iostream>

class A;
class B;
class C;

class Base
{
	public:
		virtual ~Base(void);
		Base	*generate(void);
		void	identify(Base *p);
		void	identify(Base &p);
};

#endif
