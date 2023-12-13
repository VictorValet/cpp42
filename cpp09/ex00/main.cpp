/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:45:32 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/13 16:01:27 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	(void) argv;
	if (argc != 3)
	{
		std::cout << "Wrong number of arguments!\n";
		return (1);
	}
	std::string	db(argv[1]);
	std::string	compare(argv[2]);
	if (db.size() < 4 || db.compare(db.size() - 4, 4, ".csv") != 0)
	{
		std::cout << "Wrong database extension!\n";
		return (1);
	}
	BitcoinExchange change;
	try
	{
		change.loadDB(db);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::map<std::string, double>::iterator it;
	std::map<std::string, double>::iterator ite = change.end();
	for (it = change.begin(); it != ite; it++)
		std::cout << it->first << " : " << it->second << std::endl;
}
