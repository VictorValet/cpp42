/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestClass.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:40:15 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/29 15:10:35 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTCLASS_HPP
# define TESTCLASS_HPP

# include "ScalarConverter.hpp"

class TestClass : public ScalarConverter
{
	public:
		TestClass(void);
		~TestClass(void);

	private:
		TestClass(const TestClass &original);
		TestClass	&operator=(const TestClass &original);
};

#endif
