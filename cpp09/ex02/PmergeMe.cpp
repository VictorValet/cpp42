/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:49:02 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/20 10:59:29 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(char **argv)
{
	this->parse_arguments(argv);
	
	for (unsigned int i = 0; i < this->_vector.size(); i++)
		std::cout << this->_vector[i] << " ";
	std::cout << '\n';
	this->recursive_sort(1, this->_vector);
	for (unsigned int i = 0; i < this->_vector.size(); i++)
		std::cout << this->_vector[i] << " ";
	std::cout << '\n' << '\n';

	for (std::list<int>::const_iterator it = this->_list.begin(); it != this->_list.end(); it++)
		std::cout << *it << " ";
	std::cout << '\n';
	this->recursive_sort(1, this->_list);
	// for (std::list<int>::const_iterator it = this->_list.begin(); it != this->_list.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << '\n';

	return ;
}

PmergeMe::PmergeMe(const PmergeMe &original)
{
	*this = original;
	return ;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &original)
{
	(void) original;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	return ;
}


void	PmergeMe::parse_arguments(char **argv)
{
	while (*argv)
	{
		std::string arg(*argv);
		//verification positive integer < 2147483648
		int n = atoi(*argv);
		this->_vector.push_back(n);
		this->_list.push_back(n);
		argv++;
	}
}

template<typename T>
T	PmergeMe::move(T it, long long int n)
{
	while (--n >= 0)
		it++;
	while (++n <= 0)
		it--;
	return (it);
}

typename T::iterator	left = this->move(begin, range - 1);
typename T::iterator	right = this->move(left, range);

template<typename T>
void	PmergeMe::sort_range(unsigned int range, T &cont)
{
	size_t					size = cont.size();
	typename T::iterator	begin = cont.begin();
	typename T::iterator	left = begin + range - 1;
	typename T::iterator	right = left + range;
	while (std::distance(begin, right) < static_cast<long long>(size))
	{
		if (*left > *right)
			std::swap_ranges(left - range + 1, left + 1, left + 1);
		right += range;
		left = right;
		right += range;
	}	
}

template<typename T>
void	PmergeMe::insert_range(unsigned int range, T &cont)
{
	size_t		size = cont.size();
	typename T::iterator	begin = cont.begin();
	typename T::iterator	left;
	typename T::iterator	right;
	for (unsigned int i = range; i <= (size - range); i += range)
	{
		left = begin + range - 1;
		right = left + i;
		while (left != right)
		{
			if (*left > *right)
			{
				T copy(right - range + 1, right + 1);
				cont.erase(right - range + 1, right + 1);
				cont.insert(left - range + 1, copy.begin(), copy.end());
			}
			left += range;
		}
	}
}

template<typename T>
void	PmergeMe::recursive_sort(unsigned int range, T &cont)
{
	if (range > cont.size() / 2)
		return ;
	this->sort_range(range, cont);
	this->recursive_sort(range * 2, cont);
	this->insert_range(range, cont);
}
