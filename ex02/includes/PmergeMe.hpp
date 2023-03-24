/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:39:21 by antbarbi          #+#    #+#             */
/*   Updated: 2023/03/24 12:00:12 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
 #define PMERGEME_HPP
 #include <iostream>
 #include <cstring>

class PmergeMe
{
	public:

		PmergMe(std::string str);
		PmergeMe(PmergeMe const &rhs);
		~PmergeMe();

		PmergeMe &operator =(const PmergeMe &rhs);

	private:
	
}

#endif