/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:45:32 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/18 09:43:29 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Wrong number of arguments!\n";
		return (1);
	}
	std::string	db(argv[1]);
	std::string	input(argv[2]);
	if (db.size() < 4 || db.compare(db.size() - 4, 4, ".csv") != 0)
	{
		std::cout << "Wrong database extension!\n";
		return (1);
	}
	BitcoinExchange	change;
	try
	{
		change.loadDB(db);
		change.display(input);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
