/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:59:32 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/04 14:30:57 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <climits>
# include <iomanip>
# include <iostream>
# include <math.h>

enum types
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE	
};

class Data
{
	private:
		Data(void);
		Data(const Data &original);
		Data	&operator=(const Data &original);
		char		c;
		int			i;
		float		f;
		double		d;
		static bool	(*type[4])(std::string);
		static void	(*convert[4])(std::string, Data &);

	public:
		class ConversionErrorException: public std::exception		
		{
			public:
				ConversionErrorException(const std::string str);
				~ConversionErrorException(void) throw();
				const char	*what() const throw();
			
			private:	
				const std::string	text;		
		};
		Data(std::string str);
		~Data(void);
		char		getChar(void) const;
		int			getInt(void) const;
		float		getFloat(void) const;
		double		getDouble(void) const;
		void		setChar(char new_c);
		void		setInt(int new_i);
		void		setFloat(float new_f);
		void		setDouble(double new_d);
		void		printC(long long v);
		void		printI(double l);
		void		printF(void);
		void		printD(void);
};

#endif
