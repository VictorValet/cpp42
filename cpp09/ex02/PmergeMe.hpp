/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:49:00 by vvalet            #+#    #+#             */
/*   Updated: 2024/01/04 15:59:32 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstdlib>
# include <sys/time.h>
# include <iostream>
# include <list>
# include <vector>

class PmergeMe
{
	public:
		PmergeMe(char **argv);
		~PmergeMe(void);

	private:
		unsigned int	Jacobsthal(unsigned int n);
		void			verify_arguments(char **argv);
		template <typename T>
		void			fill_container(char **argv, T &cont);
		template <typename T>
		T				move(T it, long long int n);
		template <typename T>
		void			sort_range(unsigned int range, T &cont);
		template<typename T>
		T				next_element_range(T left, unsigned int i, unsigned int range, unsigned int size);
		template <typename T>
		void			insert_range(unsigned int range, T &cont);
		template <typename T>
		void			recursive_sort(unsigned int range, T &cont);
		template <typename T>
		void			insert(unsigned int range, T &cont);
		template<typename T>
		long long		chrono_sort(char **argv, T &cont);
		std::vector<int>	_vector;
		std::list<int>		_list;
		long long			vector_chrono;
		long long			list_chrono;
		unsigned long long	vector_comp;
		// unsigned long long	list_comp;
		PmergeMe(void);
		PmergeMe(const PmergeMe &original);
		PmergeMe	&operator=(const PmergeMe &original);
		class ArgumentsException : public std::exception{
			const char *what(void) const throw();
		};
};

#endif
