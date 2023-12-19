/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:49:00 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/19 10:52:14 by vvalet           ###   ########.fr       */
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
		PmergeMe(void);
		PmergeMe(const PmergeMe &original);
		PmergeMe	&operator=(const PmergeMe &original);
		~PmergeMe(void);

	private:
		void	parse_arguments(char **argv);
		std::vector<int>	_vector;
		std::list<int>		_list;
};

#endif
