/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:39:21 by antbarbi          #+#    #+#             */
/*   Updated: 2023/03/29 15:28:38 by antbarbi         ###   ########.fr       */
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
// https://www.geeksforgeeks.org/merge-sort/
// https://www.programiz.com/dsa/merge-sort
// https://stackoverflow.com/questions/26478139/properly-combining-merge-sort-and-insertion-sort-in-c

typedef	std::list<int>::iterator literator;
typedef std::deque<int>::iterator diterator;

class PmergeMe
{
	public:

		PmergeMe();
		PmergeMe(PmergeMe const &rhs);
		~PmergeMe();

		PmergeMe &operator =(const PmergeMe &rhs);



		void	add(std::string value);
		void	print() const;
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