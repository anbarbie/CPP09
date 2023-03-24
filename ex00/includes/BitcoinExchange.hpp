/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:06:46 by antbarbi          #+#    #+#             */
/*   Updated: 2023/03/24 11:35:39 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP
 #include <iostream>
 #include <fstream>
 #include <cstring>
 #include <vector>
 #include <stdlib.h>
 #include <limits>
 #include <sys/stat.h>
 #include <sys/types.h>

 #define my_int(string) (atoi(string.c_str()))
 #define my_double(string) (atof(string.c_str()))

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string input_file);
		BitcoinExchange(BitcoinExchange const &rhs);
		~BitcoinExchange();

		BitcoinExchange &operator =(BitcoinExchange const &rhs);

		void			trade();

		typedef std::vector<std::string>::iterator iterator;

	private:
		BitcoinExchange();
		void			_init(std::string input_file);
		void			_read_input(std::ifstream &file);
		void			_read_data(std::ifstream &file);
		size_t			_find_best_date(std::string date_req) const;
		double			_exchange(size_t data_i, size_t input_i) const;

		std::vector<std::string>	_data_date;
		std::vector<std::string>	_data_rate;
		std::vector<std::string>	_input_date;
		std::vector<std::string>	_input_value;
};

class OpenFileError : public std::exception
{
	public:
	
		virtual const char *what() const throw()
		{
			return ("throw(): Error: could not open the file.");
		}	
};

class FileFormatError : public std::exception
{
	public:
	
		virtual const char *what() const throw()
		{
			return ("throw(): Error: wrong file format.");
		}	
};

class Underflow : public std::exception
{
	public:
	
		virtual const char *what() const throw()
		{
			return ("Error: not a positive number.");
		}	
};

class NotANum : public std::exception
{
	public:
	
		virtual const char *what() const throw()
		{
			return ("Error: not a valid number.");
		}	
};

class BadInput : public std::exception
{
	public:
	
		virtual const char *what() const throw()
		{
			return ("Error: bad input => ");
		}	
};

class Overflow : public std::exception
{
	public:
	
		virtual const char *what() const throw()
		{
			return ("Error: too large a number.");
		}	
};

#endif