/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:17:05 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/14 10:26:24 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map> 

class BitcoinExchange : public std::map<std::string, double>
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &original);
		BitcoinExchange	&operator=(const BitcoinExchange &original);
		~BitcoinExchange(void);
		void	loadDB(const std::string file);
		
	private:
		void	isvalidDate(std::string line) const;
		void	isvalidFloat(std::string line) const;
		void	isunique(std::string line) const;
		void	addline(const std::string line);
		class OpenFailureException : public std::exception{
			public:
				const char* what(void) const throw();
		};
		class ParsingException : public std::exception{
			public:
				ParsingException(const std::string str);
				~ParsingException(void) throw();
				const char* what(void) const throw();
			private:
				const std::string _str;
		};
};

#endif
