/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:31:34 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/12 11:47:26 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <list>
# include <climits>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &original);
		Span	&operator=(const Span &original);
		~Span(void);
		std::list<int>				getNumbers(void) const;
		unsigned int				getMax(void) const;
		std::list<int>::iterator	begin(void);
		std::list<int>::iterator	end(void);
		void						addNumber(int i);
		unsigned int				shortestSpan(void) const;
		unsigned int				longestSpan(void) const;
		void						fillNumbers(std::list<int>::iterator start, std::list<int>::iterator end);
		
	private:
		Span(void);
		const unsigned int	_max;
		std::list<int>		_numbers;
		class NoSpaceException : public std::exception{
			public:
				const char	*what() const throw();
		};
		class NoSpanException : public std::exception{
			public:
				const char	*what() const throw();
		};
};

#endif
