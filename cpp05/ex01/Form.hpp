/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:37:40 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/27 10:11:55 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(const std::string name, int sign_grade, int exec_grade);
		Form(const Form &original);
		~Form(void);
		std::string	getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		void		beSigned(Bureaucrat b);
		
	private:
		Form	&operator=(const Form &original);
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_exec_grade;
		class GradeTooHighException: public std::exception
		{
			public: 
				const char	*what() const throw();
		};
		class GradeTooLowException: public std::exception		
		{
			public: 
				const char	*what() const throw();
		};
		class AlreadySignedException: public std::exception		
		{
			public: 
				const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Form &f);

#endif
