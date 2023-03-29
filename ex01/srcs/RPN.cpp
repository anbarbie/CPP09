/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:32:02 by antbarbi          #+#    #+#             */
/*   Updated: 2023/03/29 12:18:16 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string expr) : _expr(expr)
{
	if (_expr.find_first_not_of("0123456789/*-+ ") != std::string::npos)
		throw WrongExpression();
	_Chck_expr();
}

RPN::RPN(RPN const &rhs)
{
	*this = rhs;
}

RPN::~RPN() {};

RPN &RPN::operator = (RPN const &rhs)
{
	if (this == &rhs)
		return *this;
	_operand = rhs._operand;
	_expr = rhs._expr;
	return *this;
}

void	RPN::_Chck_expr() const
{
	size_t	cpt_num = 0;
	size_t	cpt_op = 0;
	for (size_t i = 0; i < _expr.size(); i++)
	{
		if (i % 2 == 0)
		{
			if (_expr[i] == ' ')
				throw WrongExpression();
			if (isdigit(_expr[i]))
				++cpt_num;
			else  
				++cpt_op;
		}
		if (i % 2 == 1)
			if (_expr[i] != ' ')
				throw WrongExpression();
		if (cpt_num == cpt_op)
			throw WrongExpression();
	}
	if (cpt_op >= cpt_num)
		throw WrongExpression();
}

void	RPN::_eval(char sign)
{
	double second = _operand.top();
	_operand.pop();
	double first = _operand.top();
	_operand.pop();
	switch (sign)
	{
		case '+': first += second; break;
		case '-': first -= second; break;
		case '*': first *= second; break;
		case '/': first /= second; break;
	}
	_operand.push(first);
}

void	RPN::calculate()
{
	for (size_t i = 0; i < _expr.size(); i+=2)
	{
		if (isdigit(_expr[i]))
			_operand.push(my_double(_expr, i));
		else
			_eval(_expr[i]);
	}
	if (_operand.size() != 1)
		throw UnfinishedCalculation();
	std::cout << _operand.top() << std::endl;
}