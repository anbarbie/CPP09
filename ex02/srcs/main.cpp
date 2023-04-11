/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:40:08 by antbarbi          #+#    #+#             */
/*   Updated: 2023/03/29 13:47:18 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int 	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Not enough arguments." << std::endl;
		return -1;
	}
	PmergeMe alg;
	try
	{
		for (int i = 1; argv[i]; i++)
			alg.add(argv[i]);
		alg.sort();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}