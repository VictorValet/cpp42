/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:49:02 by vvalet            #+#    #+#             */
/*   Updated: 2024/01/05 07:10:26 by vvalet           ###   ########.fr       */
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
	this->list_chrono = this->chrono_sort(argv, this->_list);

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
	std::cout << "Time to process a range of " <<  this->_vector.size() << " elements with std::list : " 
		<< this->list_chrono / 1000000 << " sec, " << list_chrono % 1000000 << " microsec\n";
	std::cout << "comparisons: " << this->vector_comp / 2 << '\n';
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
unsigned int	PmergeMe::Jacobsthal(unsigned int n)
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
void	PmergeMe::sort_range(unsigned int range, T &cont)
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

//explication des formules!
template<typename T>
T	PmergeMe::next_element_range(T begin, unsigned int i, unsigned int range, unsigned int size)
{
	long long int	nth_jacobsthal;
	long long int	jacobsthal;
	long long int	prev_jacobsthal;
	long long int	index_jacobsthal;
	long long int	moves;

	nth_jacobsthal = 1;
	while (this->Jacobsthal(nth_jacobsthal) < i)//va prendre des plombes????
		nth_jacobsthal++;
	jacobsthal = Jacobsthal(nth_jacobsthal);
	prev_jacobsthal = Jacobsthal(nth_jacobsthal - 1);
	index_jacobsthal = i - prev_jacobsthal;
	moves = ((3 * range) - 1) + ((jacobsthal - index_jacobsthal) * 2 * range);
	std::cout << "Range: " << range << " | Iteration: " << i << " | Jacobsthal: " << jacobsthal << " | Index jacobsthal: " 
		<< index_jacobsthal << " | Moves: " << moves << '\n';
	if ((size - range) / (range * 2) < jacobsthal)//si on déborde du cont en cherchant le prochain element a trier
	{
		// if (range > 1)
		// 	moves -= range * (jacobsthal - (size - range) / (range * 4));//STILL WROOOOONG!
		// else
		// 	moves -= 2;
		if ((size - (size % range)) % (2 * range) == range)
			moves -= (((3 * range)) + ((jacobsthal - 1) * 2 * range)) - (size - (size % range));
		else
			moves -= (((3 * range)) + ((jacobsthal - 1) * 2 * range)) - ((size - (size % range)) - range);
	}
	
	std::cout << "Range: " << range << " | Iteration: " << i << " | Jacobsthal: " << jacobsthal << " | Index jacobsthal: " 
		<< index_jacobsthal << " | Moves: " << moves << '\n';
	
	return (move(begin, moves));
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

template <typename T>
void	PmergeMe::insert(unsigned int range, T &cont)
{
	if (cont.size() < 3 * range)//3 (insérer le dernier groupe s'il est seul mais entier)
		return ;
	T copy;

	//copy high chain and first element of low chain
	copy_high_chain(cont, copy, range);

	std::cout << '\n' << "RANGE: " << range << '\n' << '\n';
	
	//insert elements of low chain
	typename T::iterator	left;
	typename T::iterator	right;
	for (unsigned int i = 1; copy.size() < cont.size() - (cont.size() % range); i++)//virer la fct size plus haut //une fois de trop?
	{	
		left = move(copy.begin(), range - 1);
		right = next_element_range(cont.begin(), i, range, cont.size());

		//find place where insert (the left iterator)
		for (unsigned int j = range; j < copy.size(); j += range) //a optimiser
		{
			this->vector_comp++;//
			if (*left > *right)
				break ;
			left = move(left, range);
		}
		if (*left > *right)
			left = move(left, - static_cast<long long>(range));

		std::cout << "Left: " << *move(left, 1) << " | Right: " << *right << '\n';			
		copy.insert(move(left, 1), move(right, 1 - static_cast<long long>(range)), move(right, 1));//
		std::cout << "cont :";
		for (typename T::iterator it = cont.begin(); it != cont.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << '\n';
		std::cout << "copy :";
		for (typename T::iterator it = copy.begin(); it != copy.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << '\n' << '\n';
	}

	//copy remaining elements
	copy.insert(copy.end(), move(cont.end(), -static_cast<long long>(cont.size() % range)), cont.end());//
	
	//copy the copy
	cont = copy;
}

template<typename T>
void	PmergeMe::recursive_sort(unsigned int range, T &cont)
{
	if (range > cont.size() / 2)
		return ;
	this->sort_range(range, cont);
	this->recursive_sort(range * 2, cont);
	this->insert(range, cont);
}

const char *PmergeMe::ArgumentsException::what(void) const throw()
{
	return ("Error: wrong argument");
}
