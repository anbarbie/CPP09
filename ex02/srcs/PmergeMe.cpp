/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:40:05 by antbarbi          #+#    #+#             */
/*   Updated: 2023/03/29 15:44:55 by antbarbi         ###   ########.fr       */
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

void merge(std::deque<int> &deque, int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = list[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = list[q + 1 + j];

  // Maintain current index of sub-listays and main listay
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      list[k] = L[i];
      i++;
    } else {
      list[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    list[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    list[k] = M[j];
    j++;
    k++;
  }
}

// void mergeSort(std::list<int> &list, literator l, literator r)
// {
//   if (l < r) {
// 	literator m = l + 

//     mergeSort(list, l, m);
//     mergeSort(list, m + 1, r);
//     merge(list, l, m, r);
//   }
// }

void mergeSort(std::deque<int> &deque, diterator l, diterator r)
{
  if (l < r) {
	diterator m = l + (r - 1) / 2;

    mergeSort(deque, l, m);
    mergeSort(deque, m + 1, r);
    merge(deque, l, m, r);
  }
}

void	PmergeMe::sort()
{
	if (_list.size() == 1)
		return ;
	// mergeSort(_list, _list.begin(), _list.end());
	mergeSort(_deque, _deque.begin(), _deque.end());
}