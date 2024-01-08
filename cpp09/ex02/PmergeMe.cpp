/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:49:02 by vvalet            #+#    #+#             */
/*   Updated: 2024/01/08 10:47:00 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(char **argv):
_comp(0), _vector_comp(0), _list_comp(0) 
{
	this->verify_arguments(argv);
	
	for (unsigned int i = 0; argv[i]; i++)
	{
		std::cout << argv[i];
		if (argv[i] + 1 != 0)
			std::cout << " ";
	}
	std::cout << '\n';

	this->_vector_chrono = this->chrono_sort(argv, this->_vector);
	this->_vector_comp = this->_comp;
	this->_list_chrono = this->chrono_sort(argv, this->_list);
	this->_list_comp = this->_comp;

	for (unsigned int i = 0; i < this->_vector.size(); i++)
	{
		std::cout << this->_vector[i];
		if (i < this->_vector.size() - 1)
			std::cout << " ";
	}
	std::cout << '\n';

	std::cout << "Vector is sorted: " << is_sorted(_vector.begin(), _vector.end()) << '\n';
	std::cout << "List is sorted: " << is_sorted(_list.begin(), _list.end()) << '\n';

	std::cout << "Time to process a range of " <<  this->_vector.size() << " elements with std::vector : " 
		<< this->_vector_chrono / 1000000 << " sec, " << this->_vector_chrono % 1000000 << " microsec, with a total of "
		<<  this->_vector_comp << " comparisons\n";
	std::cout << "Time to process a range of " <<  this->_vector.size() << " elements with std::list : " 
		<< this->_list_chrono / 1000000 << " sec, " << this->_list_chrono % 1000000 << " microsec, with a total of "
		<<  this->_list_comp << " comparisons\n";
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

//Returns nth jacobsthal number
unsigned int	Jacobsthal(unsigned int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2)); 
}

void	PmergeMe::verify_arguments(char **argv)
{
	while (*argv)
	{
		int 		i = 0;
		while ((*argv)[i])
		{
			if (isdigit((*argv)[i]) == false)
				throw (ArgumentsException());
			i++;
		}
		std::string	check(*argv);
		if (check.size() > 10 || (check.size() == 10 && check > "2147483647"))
			throw (ArgumentsException());
		argv++;
	}
}

template<typename T>
void	PmergeMe::fill_container(char **argv, T &cont)
{
	while (*argv)
	{
		int n = atoi(*argv);
		cont.push_back(n);
		argv++;
	}
}

template<typename T>
T	move(T it, long long n)
{
	while (n > 0)
	{
		it++;
		n--;
	}	
	while (n < 0)
	{
		it--;
		n++;
	}	
	return (it);
}

template<typename T>
void	PmergeMe::sort_pairs_range(unsigned int range, T &cont)
{
	long long				limit = cont.size() / (range * 2);
	typename T::iterator	left = move(cont.begin(), range - 1);
	typename T::iterator	right = move(left, range);
	for (int i = 0; i < limit; i++)
	{
		this->_comp++;
		if (*left > *right)
		{
			std::swap_ranges(move(right, 1 - static_cast<long long>(range)),
			move(right, 1), move(left, 1 - static_cast<long long>(range)));
		}
		right = move(right, range);
		left = right;
		right = move(right, range);
	}
}

template <typename T>
void	copy_high_chain(T &cont, T &copy, unsigned int range)
{
	typename T::iterator it = move(cont.begin(), range);
	unsigned int x = range * 2 - 1;
	while (x < cont.size())
	{
		copy.insert(copy.end(), it, move(it, range));
		it = move(it, range * 2);
		x += range * 2;
	}
	copy.insert(copy.begin(), cont.begin(), move(cont.begin(), range));	
}

//explication des formules!
template<typename T>
T	next_element_range(T begin, unsigned int i, unsigned int range, unsigned int size)
{
	long long int	nth_jacobsthal;
	long long int	jacobsthal;
	long long int	prev_jacobsthal;
	long long int	index_jacobsthal;
	long long int	moves;

	nth_jacobsthal = 1;
	while (Jacobsthal(nth_jacobsthal) < i)
		nth_jacobsthal++;
	jacobsthal = Jacobsthal(nth_jacobsthal);
	prev_jacobsthal = Jacobsthal(nth_jacobsthal - 1);
	index_jacobsthal = i - prev_jacobsthal;
	moves = ((3 * range) - 1) + ((jacobsthal - index_jacobsthal) * 2 * range);
	if ((size - range) / (range * 2) < jacobsthal)//si on déborde du cont en cherchant le prochain element a trier
	{
		if ((size - (size % range)) % (2 * range) == range)
			moves -= (((3 * range)) + ((jacobsthal - 1) * 2 * range)) - (size - (size % range));
		else
			moves -= (((3 * range)) + ((jacobsthal - 1) * 2 * range)) - ((size - (size % range)) - range);
	}
	return (move(begin, moves));
}

template<typename T>
typename T::iterator	PmergeMe::binary_search(T &cont, int n, unsigned int range)
{
	typename T::iterator	left = move(cont.begin(), range - 1);
	typename T::iterator	right = cont.end();
	typename T::iterator	last = --right;
	unsigned int			distance = std::distance(left, right);

	// std::cout << "Number: " << n << " | Iteration: " << i << " | Distance to compare: " << distance << " | Range: " << range << '\n';		
	// std::cout << "copy: ";
	// for (typename T::iterator it = cont.begin(); it != cont.end(); it++)
	// {
	// 	std::cout << *it << " ";
	// }
	// std::cout << '\n';

    while ((range == 1 && left != right) || distance > 1)
	{
        typename T::iterator mid = move(left, range * (distance / (2 * range)));

		this->_comp++;
        if (*mid < n) 
            left = move(mid, range);
		else 
            right = mid;
		distance = std::distance(left, right);
    }
	if (left != last || n < *left)
		left = move(left, - static_cast<long long>(range));
	// std::cout << "Left: " << *left << " | distance from 0: " << std::distance(cont.begin(), left) << " | Right: " << *right << " | distance from 0: " << std::distance(cont.begin(), right) << '\n' << '\n';

	return (left);
}

template<typename T>
void	PmergeMe::insert_low_chain(T &cont, T &copy, unsigned int range)
{
	typename T::iterator	left;
	typename T::iterator	right;
	typename T::iterator	cont_begin = cont.begin();
	unsigned int			cont_size = cont.size();
	
	for (unsigned int i = 1; copy.size() < cont_size - (cont_size % range); i++)
	{
		right = next_element_range(cont_begin, i, range, cont_size);
		left = this->binary_search(copy, *right, range);
		copy.insert(move(left, 1), move(right, 1 - static_cast<long long>(range)), move(right, 1));//faire en sorte qu'on ait les bons index dans les fonctions du dessus
	}
}

template <typename T>
void	PmergeMe::insert_range(unsigned int range, T &cont)
{
	if (cont.size() < 3 * range)
		return ;
	T copy;

	copy_high_chain(cont, copy, range);
	this->insert_low_chain(cont, copy, range);
	copy.insert(copy.end(), move(cont.end(), -static_cast<long long>(cont.size() % range)), cont.end());
	cont = copy;
}

template<typename T>
void	PmergeMe::recursive_sort(unsigned int range, T &cont)
{
	if (range > cont.size() / 2)
		return ;
	this->sort_pairs_range(range, cont);
	this->recursive_sort(range * 2, cont);
	this->insert_range(range, cont);
}

template<typename T>
long long	PmergeMe::chrono_sort(char **argv, T &cont)
{
	timeval		beginning;
	timeval		end;
	long long	chrono;

	this->_comp = 0;
	gettimeofday(&beginning, NULL);
	this->fill_container(argv, cont);
	this->recursive_sort(1, cont);
	gettimeofday(&end, NULL);
	chrono = (end.tv_sec - beginning.tv_sec) * 1000000 + (end.tv_usec - beginning.tv_usec);
	return (chrono);
}

const char *PmergeMe::ArgumentsException::what(void) const throw()
{
	return ("Error: wrong argument");
}
