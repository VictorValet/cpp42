/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:37:40 by vvalet            #+#    #+#             */
/*   Updated: 2023/11/28 10:44:59 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		AForm(const std::string name, int sign_grade, int exec_grade);
		AForm(const AForm &original);
		virtual 		~AForm(void);
		std::string		getName() const;
		bool			getSigned() const;
		int				getSignGrade() const;
		int				getExecGrade() const;
		void			beSigned(Bureaucrat b);
		virtual void	execute(Bureaucrat const &executor) const = 0;
	
	protected:
		std::string		getTarget() const;
		void			setTarget(std::string new_target);
		void			checkRequirements(Bureaucrat b) const;
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
		class UnsignedException: public std::exception		
		{
			public: 
				const char	*what() const throw();
		};
		
	
	private:
		AForm	&operator=(const AForm &original);
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_exec_grade;
		std::string			_target;
};

std::ostream	&operator<<(std::ostream &o, AForm &f);

#endif
