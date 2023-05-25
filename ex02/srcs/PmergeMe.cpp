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

int		median_val(std::list<int> &list)
{
	unsigned int index = 0;
	literator it = list.begin();
	for (; index < list.size() / 2; index++)
		it++;
	return *it;
}

std::list<int>	Sort_BtoA(std::list< std::pair<int, int> > &pair_list)
{
	std::list<int> list;

	for (piterator it = pair_list.begin(); it != pair_list.end(); it++)
		if (it->first != -1)
			list.push_back(it->first);
	for (piterator it = pair_list.begin(); it != pair_list.end(); it++)
	{
		if (it->first != -1 || it->second != -1)
		{
			if (it->second >= median_val(list))
			{
				literator rev_it = list.end();
				rev_it--;
				for (; it->second < *rev_it; rev_it--);
				list.insert(++rev_it, it->second);
				it->second = -1;
			}
			else
			{
				literator lit = list.begin();
				for (; it->second > *lit; lit++);
				list.insert(lit, it->second);
				it->second = -1;
			}
		}
	}
	return list;
}

void	mergeSort(std::list<int> &_list)
{
	std::list< std::pair<int, int> > tmp_list = makePair(_list);
	Sort_A(tmp_list);
	_list = Sort_BtoA(tmp_list);
}

//////////////////////////////////////////////////// DEQUE ///////////

std::deque< std::pair<int, int> >	makePair(std::deque<int> _list)
{
	std::deque< std::pair<int, int> > tmp_list;
	int	i = 0;
	std::pair<int, int> pair;
	
	for (diterator it = _list.begin(); it != _list.end(); it++)
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
		diterator it = --_list.end();
		pair.second = *it;
	}
	tmp_list.push_back(pair);
	for (pditerator it = tmp_list.begin(); it != tmp_list.end(); it++)
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

void	Sort_A(std::deque< std::pair<int, int> > &list)
{
	pditerator it = list.begin();
	pditerator it_plus = list.begin();
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

int		median_val(std::deque<int> &list)
{
	unsigned int index = 0;
	diterator it = list.begin();
	for (; index < list.size() / 2; index++)
		it++;
	return *it;
}

std::deque<int>	Sort_BtoA(std::deque< std::pair<int, int> > &pair_list)
{
	std::deque<int> list;

	for (pditerator it = pair_list.begin(); it != pair_list.end(); it++)
		if (it->first != -1)
			list.push_back(it->first);
	for (pditerator it = pair_list.begin(); it != pair_list.end(); it++)
	{
		if (it->first != -1 || it->second != -1)
		{
			if (it->second >= median_val(list))
			{
				diterator rev_it = list.end();
				rev_it--;
				for (; it->second < *rev_it; rev_it--);
				list.insert(++rev_it, it->second);
				it->second = -1;
			}
			else
			{
				diterator lit = list.begin();
				for (; it->second > *lit; lit++);
				list.insert(lit, it->second);
				it->second = -1;
			}
		}
	}
	return list;
}

void	mergeSort(std::deque<int> &_list)
{
	std::deque< std::pair<int, int> > tmp_list = makePair(_list);
	Sort_A(tmp_list);
	_list = Sort_BtoA(tmp_list);
}

// DEQUE END ////////////////////////////////////////////////////////////

void	PmergeMe::sort()
{
	if (_list.size() == 1)
		return ;
	std::cout << "Before:  ";
	for (literator it = _list.begin(); it != _list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << "After:   ";

	struct timeval startList, endList;
	gettimeofday(&startList, NULL);
	mergeSort(_list);
	gettimeofday(&endList, NULL);
	double durationList = (endList.tv_sec - startList.tv_sec) * 1000000.0 + (endList.tv_usec - startList.tv_usec);

	struct timeval startDeque, endDeque;
	gettimeofday(&startDeque, NULL);
	mergeSort(_deque);
	gettimeofday(&endDeque, NULL);
	double durationDeque = (endDeque.tv_sec - startDeque.tv_sec) * 1000000.0 + (endDeque.tv_usec - startDeque.tv_usec);

	for (literator it = _list.begin(); it != _list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list: " << durationList / 1000000.0 << " s" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque: " << durationDeque / 1000000.0 << " s" << std::endl;
}