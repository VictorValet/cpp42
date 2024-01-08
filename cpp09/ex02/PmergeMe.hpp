/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:49:00 by vvalet            #+#    #+#             */
/*   Updated: 2024/01/08 10:26:07 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstdlib>
# include <sys/time.h>
# include <iostream>
# include <list>
# include <vector>
# include <algorithm>

class PmergeMe
{
	public:
		PmergeMe(char **argv);
		~PmergeMe(void);

	private:
		void					verify_arguments(char **argv);
		template <typename T>
		void					fill_container(char **argv, T &cont);
		template <typename T>
		void					sort_pairs_range(unsigned int range, T &cont);
		template<typename T>
		typename T::iterator	binary_search(T &cont, int n, unsigned int range);
		template<typename T>
		void					insert_low_chain(T &cont, T &copy, unsigned int range);
		template <typename T>
		void					insert_range(unsigned int range, T &cont);
		template <typename T>
		void					recursive_sort(unsigned int range, T &cont);
		template<typename T>
		long long				chrono_sort(char **argv, T &cont);
		std::vector<int>	_vector;
		std::list<int>		_list;
		long long			_vector_chrono;
		long long			_list_chrono;
		unsigned long long	_comp;
		unsigned long long	_vector_comp;
		unsigned long long	_list_comp;
		PmergeMe(void);
		PmergeMe(const PmergeMe &original);
		PmergeMe	&operator=(const PmergeMe &original);
		class ArgumentsException : public std::exception{
			const char *what(void) const throw();
		};
};

#endif
