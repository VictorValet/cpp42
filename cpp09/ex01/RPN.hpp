/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:59:30 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/18 16:38:19 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <algorithm>
# include <iostream>
# include <stack>

class RPN : public std::stack<int>
{
	public:
		RPN(char *str);
		~RPN(void);

	private:
		void	validate_token(std::string tok) const;
		void	validate_operation(char const op, int const &left_operand, int const &right_operand) const;
		void	make_operation(char op);
		void	process_string(std::string str);
		RPN(void);
		RPN(const RPN &original);
		RPN	&operator=(const RPN &original);
		class WrongInputException : public std::exception {
			public:
				WrongInputException(const std::string str);
				~WrongInputException(void) throw();
				const char *what(void) const throw();
			private:
				const std::string	_str;	
		};
};

#endif
