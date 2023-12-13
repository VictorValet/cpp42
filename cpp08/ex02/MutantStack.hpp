/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:25:06 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/13 10:44:02 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template<typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack<T, Container> (void) : std::stack<T, Container>() {}
		MutantStack<T, Container> (const MutantStack<T, Container> &original) {this->c = original.c;};
		MutantStack<T, Container> &operator=(const MutantStack<T, Container> &original)
		{
			if (this != &original)
				this->c = original.c;
			return (*this);
		}
		~MutantStack(void) {}
		typedef typename	Container::iterator					iterator;
		typedef typename	Container::const_iterator			const_iterator;
		typedef typename	Container::reverse_iterator			reverse_iterator;
		typedef typename	Container::const_reverse_iterator	const_reverse_iterator;
		iterator				begin(void) { return (this->c.begin()); }
		iterator				end(void) { return (this->c.end()); }
		const_iterator			cbegin(void) { return (this->c.cbegin()); }
		const_iterator			cend(void) { return (this->c.cend()); }
		reverse_iterator		rbegin(void) { return (this->c.rbegin()); }
		reverse_iterator		rend(void) { return (this->c.rend()); }
		const_reverse_iterator	crbegin(void) { return (this->c.crbegin()); }
		const_reverse_iterator	crend(void) { return (this->c.crend()); }

	private:
};

#include "MutantStack.tpp"

#endif
