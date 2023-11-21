/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:33:59 by vvalet            #+#    #+#             */
/*   Updated: 2023/10/31 14:08:29 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Wrong number of arguments\n";
		return (1);
	}
	if (argv[1][0] == 0)
	{
		std::cerr << "Error: Searched string may not be empty\n";
		return (1);
	}
	Sed	sed(argv[1], argv[2], argv[3]);
	return (sed.replace());
}
