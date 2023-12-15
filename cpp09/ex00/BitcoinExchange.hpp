/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:17:05 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/15 11:12:37 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map> 

class BitcoinExchange : public std::map<std::string, float>
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &original);
		BitcoinExchange	&operator=(const BitcoinExchange &original);
		~BitcoinExchange(void);
		void	loadDB(const std::string db);
		void	display(const std::string input);
		
	private:
		void									isvalidDate(std::string line, std::string sep) const;
		void									isvalidFloat(std::string line) const;
		void									isvalidMult(std::string line) const;
		void									isvalidLine(std::string line, std::string sep, 
													void (BitcoinExchange::*fun)(std::string line) const) const;
		void									isunique(std::string line) const;
		std::map<std::string, float>::iterator	previous_date(std::string key) const;
		void									add_line(const std::string line);
		void									display_line(const std::string line);
		class OpenFailureException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class LineException : public std::exception
		{
			public:
				LineException(const std::string str);
				~LineException(void) throw();
				const char* what(void) const throw();
			private:
				const std::string _str;
		};
};

#endif
