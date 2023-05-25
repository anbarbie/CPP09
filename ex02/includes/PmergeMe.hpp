/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:39:21 by antbarbi          #+#    #+#             */
/*   Updated: 2023/04/04 12:02:59 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
 #define PMERGEME_HPP
 #include <iostream>
 #include <cstring>
 #include <list>
 #include <deque>
 #include <limits>
 #include <cstdlib>
 #include <sys/time.h>
 #include <iomanip>
// https://www.geeksforgeeks.org/merge-sort/
// https://www.programiz.com/dsa/merge-sort
// https://stackoverflow.com/questions/26478139/properly-combining-merge-sort-and-insertion-sort-in-c

// https://github.com/decidedlyso/merge-insertion-sort/blob/master/README.md
// https://en.wikipedia.org/wiki/Jacobsthal_number#:~:text=The%20first%20Jacobsthal%20numbers%20are,number%20that%20is%20also%20prime.



typedef	std::list<int>::iterator literator;
typedef std::deque<int>::iterator diterator;
typedef std::list< std::pair<int, int> >::iterator piterator;
typedef std::deque< std::pair<int, int> >::iterator pditerator;

class PmergeMe
{
	public:

		PmergeMe();
		PmergeMe(PmergeMe const &rhs);
		~PmergeMe();

		PmergeMe &operator =(const PmergeMe &rhs);

		void	add(std::string value);
		void	sort();

	private:
	
		void			_sort_list();
		void			_sort_deque();
		bool			_isDup(int num) const;

		std::list<int>	_list;
		std::deque<int> _deque;

};

class WrongArg : public std::exception
{
	public:
	
		virtual const char *what() const throw()
		{
			return ("throw(): Error: Wrong argument format.");
		}
};

class Overflow : public std::exception
{
	public:
	
		virtual const char *what() const throw()
		{
			return ("throw(): Error: Argument to int overflow.");
		}
};


#endif