/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:49:02 by vvalet            #+#    #+#             */
/*   Updated: 2024/01/05 18:03:40 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(char **argv):
vector_comp(0)/* , list_comp(0) */ 
{
	this->verify_arguments(argv);
	
	for (unsigned int i = 0; argv[i]; i++)
	{
		std::cout << argv[i];
		if (argv[i] + 1 != 0)
			std::cout << " ";
	}
	std::cout << '\n';

	this->vector_chrono = this->chrono_sort(argv, this->_vector);
	// this->list_chrono = this->chrono_sort(argv, this->_list);

	for (unsigned int i = 0; i < this->_vector.size(); i++)
	{
		std::cout << this->_vector[i];
		if (i < this->_vector.size() - 1)
			std::cout << " ";
	}
	std::cout << '\n';

	std::cout << "Vector is sorted: " << is_sorted(this->_vector.begin(), this->_vector.end()) << '\n';
	std::cout << "List is sorted: " << is_sorted(this->_list.begin(), this->_list.end()) << '\n';

	std::cout << "Time to process a range of " <<  this->_vector.size() << " elements with std::vector : " 
		<< this->vector_chrono / 1000000 << " sec, " << vector_chrono % 1000000 << " microsec\n";
	// std::cout << "Time to process a range of " <<  this->_vector.size() << " elements with std::list : " 
	// 	<< this->list_chrono / 1000000 << " sec, " << list_chrono % 1000000 << " microsec\n";
	std::cout << "comparisons: " << this->vector_comp << '\n';
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
unsigned int	distance_calc(T left, T right)
{
	unsigned int	distance = 0;

	while (move(left, distance) != right)
		distance++;
	return (distance);
}

template<typename T>
void	PmergeMe::sort_pairs_range(unsigned int range, T &cont)
{
	long long				limit = cont.size() / (range * 2);
	typename T::iterator	left = move(cont.begin(), range - 1);
	typename T::iterator	right = move(left, range);
	for (int i = 0; i < limit; i++)
	{
		this->vector_comp++;
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

	//calculer ca juste une fois au d2but de chaque iteration dans le fonction insert_low_chain
	//mettre les trois dans un tuple?
	nth_jacobsthal = 1;
	while (Jacobsthal(nth_jacobsthal) < i)
		nth_jacobsthal++;
	jacobsthal = Jacobsthal(nth_jacobsthal);
	prev_jacobsthal = Jacobsthal(nth_jacobsthal - 1);
	//
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
typename T::iterator	PmergeMe::binary_search(T &cont, int n, unsigned int range, unsigned int i)
{
	typename T::iterator	left;
	typename T::iterator	last = --cont.end();
	(void) i;
	
	// version 3
	left = move(cont.begin(), range - 1);
	// if (cont.size() < 3)
	// 	return (left);
	// long long int	nth_jacobsthal;
	// long long int	jacobsthal;
	// long long int	prev_jacobsthal;
	// unsigned int	distance;
	// //voir next_element_range, ou envoyer distance en parametre
	// nth_jacobsthal = 1;
	// while (Jacobsthal(nth_jacobsthal) < i)
	// 	nth_jacobsthal++;
	// jacobsthal = Jacobsthal(nth_jacobsthal);
	// prev_jacobsthal = Jacobsthal(nth_jacobsthal - 1);
	// //
	// distance = jacobsthal + prev_jacobsthal + 1;
	// typename T::iterator	right = move(left, (distance + 1) * range);
	
	typename T::iterator	right = cont.end();
	unsigned int			distance = cont.size() + 1 - range;
	std::cout << "Number: " << n << " | Iteration: " << i << " | Distance to compare: " << distance << " | Range: " << range << '\n';		
	std::cout << "Left: " << *left << '\n';
	std::cout << "copy: ";
	for (typename T::iterator it = cont.begin(); it != cont.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << '\n';
	
	//marche pour une range de 1 mais pas plus (la condition pose probleme notamment)
    while ((range == 1 && left != right) || (range != 1 && distance > range))
	{
        // typename T::iterator mid = left + (std::distance(left, right) / 2);
        // typename T::iterator mid = left + (distance(left, right) / 2);
        typename T::iterator mid = left + range * (distance / (2 * range));//verifier que les deux font la même chose sur 1

        if (*mid < n) 
            left = mid + range;
		else 
            right = mid;
		distance = distance_calc(left, right);
    }
	if (range != 1 && distance == range)
		;
	else
		left = move(left, - static_cast<long long>(range));
	std::cout << "Left: " << *left << " | distance from 0: " << std::distance(cont.begin(), left) << '\n';

	// version 2
	left = move(cont.begin(), range - 1);
	while (*left < n)
	{
		if (left == last)
		{
			left = move(left, range);
			break ;
		}
		left = move(left, range);
	}
	left = move(left, - static_cast<long long>(range));
	std::cout << "Left: " << *left << " | distance from 0: " << std::distance(cont.begin(), left) << '\n' << '\n';

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
		/* PRINT ZONE */
		std::cout << "cont: ";
		for (typename T::iterator it = cont.begin(); it != cont.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << '\n';
		/* PRINT ZONE */
		left = this->binary_search(copy, *right, range, i);
		copy.insert(move(left, 1), move(right, 1 - static_cast<long long>(range)), move(right, 1));//mettre le premier param a 0 plutot que 1
	}
}

template <typename T>
void	PmergeMe::insert_range(unsigned int range, T &cont)
{
	if (cont.size() < 3 * range)
		return ;
	T copy;

	//copy high chain and first element of low chain
	copy_high_chain(cont, copy, range);

	//insert elements of low chain
	this->insert_low_chain(cont, copy, range);

	//copy remaining elements
	copy.insert(copy.end(), move(cont.end(), -static_cast<long long>(cont.size() % range)), cont.end());

	//copy the copy
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
