/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:40:05 by antbarbi          #+#    #+#             */
/*   Updated: 2023/04/04 11:59:21 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
	*this = rhs;
}

PmergeMe::~PmergeMe() {};

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

void	PmergeMe::print() const
{
	std::cout << "LIST" << std::endl;
	for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << "DEQUE" << std::endl;
	for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

bool		ConvToInt(std::string type)
{
	double ldoubleConv = strtold(type.c_str(), NULL);
	if (ldoubleConv > std::numeric_limits<int>::max() || ldoubleConv < std::numeric_limits<int>::min())
		return false;

	return true;
}

bool	PmergeMe::_isDup(int num) const
{
	for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); it++)
		if (*it == num)
			return true;
	return false;
}

void	PmergeMe::add(std::string value)
{
	if (value.find_first_not_of("0123456789") != std::string::npos)
		throw WrongArg();
	if (!ConvToInt(value))
		throw Overflow();
	int num = atoi(value.c_str());
	if (_isDup(num))
		return ;
	_list.push_back(num);
	_deque.push_back(num);
}

std::list< std::pair<int, int> >	makePair(std::list<int> _list)
{
	std::list< std::pair<int, int> > tmp_list;
	int	i = 0;
	std::pair<int, int> pair;
	
	for (literator it = _list.begin(); it != _list.end(); it++)
	{
		if (i % 2 == 0 && i != 0)
			tmp_list.push_back(pair);
		if (i % 2 == 0)
			pair.first = *it;
		if (i % 2 == 1)
			pair.second = *it;
		i++;
	}
	if (i % 2 == 1)
	{
		pair.first = -1;
		literator it = --_list.end();
		pair.second = *it;
	}
	tmp_list.push_back(pair);
	for (piterator it = tmp_list.begin(); it != tmp_list.end(); it++)
	{
		if (it->first > it->second)
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
	return tmp_list;
}

void	Sort_A(std::list< std::pair<int, int> > &list)
{
	piterator it = list.begin();
	piterator it_plus = list.begin();
	bool reset = false;

	++it_plus;
	for (; it_plus != list.end(); it_plus++, it++)
	{
		if (it->first > it_plus->first)
		{
			while (it->first > it_plus->first &&  it_plus != list.end())
			{
				std::pair<int, int> tmp = *it;
				*it = *it_plus;
				*it_plus = tmp;
				it++; it_plus++;
			}
			reset = true;
		}
		if (reset == true)
		{
			reset = false;
			it = --list.begin();
			it_plus = list.begin();
		}
	}
}

void	mergeSort(std::list<int> _list)
{
	std::list< std::pair<int, int> > tmp_list = makePair(_list);
	Sort_A(tmp_list);
	
	for (piterator it = tmp_list.begin(); it != tmp_list.end(); it++)
		std::cout << "["  << it->first << " ; " << it->second << "]" << " ";
}

void	PmergeMe::sort()
{
	if (_list.size() == 1)
		return ;
	mergeSort(_list);
	// mergeSort(_deque, _deque.begin(), _deque.end());
}