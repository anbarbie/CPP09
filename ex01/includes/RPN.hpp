/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:33:57 by antbarbi          #+#    #+#             */
/*   Updated: 2023/03/27 13:32:56 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
 #define RPN_HPP
 #include <iostream>
 #include <cstring>
 #include <stack>
 #include <ctype.h>
 #include <stdlib.h>

 #define my_double(string, i) (atof(string.c_str() + i))

class RPN
{
	public: 

		RPN(std::string expr);
		RPN(RPN const &rhs);
		~RPN();
		
		RPN	&operator = (RPN const &rhs);

		void	print() const;
		void	calculate();

	private:

		RPN();
		void 					_Chck_expr() const;
		void					_eval(char sign);
		std::stack<double>		_operand;
		std::string				_expr;
};

class WrongExpression : public std::exception
{
	public:
	
		virtual const char *what() const throw()
		{
			return ("throw(): Error: Wrong expression format.");
		}	
};

class UnfinishedCalculation : public std::exception
{
	public:
	
		virtual const char *what() const throw()
		{
			return ("throw(): Error: More than one number left on the stack.");
		}	
};

#endif