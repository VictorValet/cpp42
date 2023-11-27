/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:59:46 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/23 16:28:41 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &original);
		Bureaucrat	&operator=(const Bureaucrat &original);
		~Bureaucrat(void);
		const std::string	getName() const;
		int					getGrade() const;
		void				higherGrade();
		void				lowerGrade();

	private:
		const std::string	_name;
		int					_grade;
		class GradeTooHighException: public std::exception
		{
			public: 
				const char	*what() const _NOEXCEPT;
		};
		class GradeTooLowException: public std::exception		
		{
			public: 
				const char	*what() const _NOEXCEPT;
		};
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &b);

#endif
