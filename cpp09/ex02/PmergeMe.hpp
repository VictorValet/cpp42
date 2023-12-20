/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:49:00 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/20 10:58:12 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <vector>

class PmergeMe
{
	public:
		PmergeMe(char **argv);
		~PmergeMe(void);

	private:
		void	parse_arguments(char **argv);
		template <typename T>
		void	sort_range(unsigned int range, T &cont);
		template <typename T>
		void	insert_range(unsigned int range, T &cont);
		template <typename T>
		void	recursive_sort(unsigned int range, T &cont);
		template <typename T>
		T		move(T it, long long int n);
		// void	vector_sort(unsigned int range);
		// void	list_sort(unsigned int range);
		std::vector<int>	_vector;
		std::list<int>		_list;
		PmergeMe(void);
		PmergeMe(const PmergeMe &original);
		PmergeMe	&operator=(const PmergeMe &original);
};

#endif
