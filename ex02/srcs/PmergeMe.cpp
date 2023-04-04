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



void	PmergeMe::sort()
{
	if (_list.size() == 1)
		return ;
	// mergeSort(_list, _list.begin(), _list.end());
	mergeSort(_deque, _deque.begin(), _deque.end());
}