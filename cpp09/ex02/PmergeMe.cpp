/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:49:02 by vvalet            #+#    #+#             */
/*   Updated: 2024/01/04 17:36:57 by vvalet           ###   ########.fr       */
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


	std::cout << "Vector is sorted: " << std::is_sorted(this->_vector.begin(), this->_vector.end()) << '\n';
	// std::cout << "List is sorted: " << std::is_sorted(this->_list.begin(), this->_list.end()) << '\n';

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
T	PmergeMe::move(T it, long long n)
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
	typename T::iterator	left = this->move(cont.begin(), range - 1);
	typename T::iterator	right = this->move(left, range);
	for (int i = 0; i < limit; i++)
	{
		this->vector_comp++;
		if (*left > *right)
		{
			std::swap_ranges(this->move(right, 1 - static_cast<long long>(range)),
			this->move(right, 1), this->move(left, 1 - static_cast<long long>(range)));
		}
		right = this->move(right, range);
		left = right;
		right = this->move(right, range);
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
	if ((size - range) / (range * 2) < jacobsthal)//si on déborde du cont en cherchant le prochain element a trier
		moves -= (((jacobsthal - prev_jacobsthal) - index_jacobsthal) * 2 * range);
	return (this->move(begin, moves));
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

template <typename T>
void	PmergeMe::insert(unsigned int range, T &cont)
{
	if (cont.size() < 3 * range)
		return ;

	std::cout << "Range: " << range << '\n';
	std::cout << "Before insert: ";
	for (typename T::iterator x = cont.begin(); x != cont.end(); x++)
		std::cout << *x << ' ';
	std::cout << '\n';
	
	//copy high chain and first element of low chain
	T copy;
	typename T::iterator it = this->move(cont.begin(), range);
	unsigned int x = range * 2 - 1;
	while (x < cont.size())
	{
		copy.insert(copy.end(), it, this->move(it, range));
		it = this->move(it, range * 2);
		x += range * 2;
	}
	copy.insert(copy.begin(), cont.begin(), this->move(cont.begin(), range));		

	for (typename T::iterator x = copy.begin(); x != copy.end(); x++)
		std::cout << *x << ' ';
	std::cout << '\n';

	//insert elements of low chain
	typename T::iterator	left;
	typename T::iterator	right;
	for (unsigned int i = 1; copy.size() / range < cont.size() / range; i++)//virer la fct size plus haut //une fois de trop?
	{	
		left = this->move(copy.begin(), range - 1);
		right = next_element_range(cont.begin(), i, range, cont.size());

		//find place where insert (the left iterator)
		for (unsigned int j = range; j < copy.size(); j += range) //a optimiser
		{
			this->vector_comp++;//
			if (*left > *right)
				break ;
			left = this->move(left, range);
		}
		std::cout << "Range: " << range << " | Place: " << std::distance(copy.begin(), left) << " | Left: " << *left << " | Right: " << *right << '\n';	
		if (*left > *right)
			left = this->move(left, - static_cast<long long>(range));
		
		copy.insert(this->move(left, 1), this->move(right, 1 - static_cast<long long>(range)), this->move(right, 1));//
		for (typename T::iterator x = copy.begin(); x != copy.end(); x++)
			std::cout << *x << ' ';
		std::cout << '\n';
	}


	//copy remaining elements
	copy.insert(copy.end(), this->move(cont.end(), -static_cast<long long>(cont.size() % range)), cont.end());//
	
	std::cout << "After  insert: ";
	for (typename T::iterator x = copy.begin(); x != copy.end(); x++)
		std::cout << *x << ' ';
	std::cout << '\n';
	
	cont = copy;
}

const char *PmergeMe::ArgumentsException::what(void) const throw()
{
	return ("Error: wrong argument");
}
