/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:31:34 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/12 14:35:56 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <climits>
# include <iostream>
# include <vector>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &original);
		Span	&operator=(const Span &original);
		~Span(void);
		std::vector<int>					getNumbers(void) const;
		unsigned int						getMax(void) const;
		std::vector<int>::const_iterator	begin(void) const;
		std::vector<int>::const_iterator	end(void) const;
		void								addNumber(int i);
		unsigned int						shortestSpan(void) const;
		unsigned int						longestSpan(void) const;
		template<typename T>
		void								addNumbers(T first, T last)
		{
			if (static_cast<unsigned int>(std::distance(first, last)) > this->_max - this->_numbers.size())
				throw (NoSpaceException());
			while (std::distance(first, last) > 0)
				this->addNumber(*(first++));
		}
		
	private:
		Span(void);
		const unsigned int	_max;
		std::vector<int>	_numbers;
		class NoSpaceException : public std::exception{
			public:
				const char	*what() const throw();
		};
		class NoSpanException : public std::exception{
			public:
				const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Span &s);

#endif
