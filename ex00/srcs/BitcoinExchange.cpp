/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:12:10 by antbarbi          #+#    #+#             */
/*   Updated: 2023/03/24 11:35:41 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string input_file)
{
	_init(input_file);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs) {*this = rhs;}

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange &BitcoinExchange::operator =(BitcoinExchange const &rhs)
{
	if (this == &rhs)
		return *this;
	_data_date = rhs._data_date;
	_data_rate = rhs._data_rate;
	_input_date = rhs._input_date;
	_input_value = rhs._input_value;
	return *this;
}

std::vector<std::string> actual_split(std::string str, std::string delimiter)
{
	std::vector<std::string> result;

	size_t	start = 0;
	size_t	end = str.find(delimiter);

	while (end != std::string::npos)
	{
		result.push_back(str.substr(start, end - start));
		start = end + delimiter.length();
		end = str.find(delimiter, start);
	}
	result.push_back(str.substr(start, end));
	return (result);
}

void	BitcoinExchange::_read_input(std::ifstream &file)
{
	std::string input_str;
	while (std::getline(file,  input_str))
	{
		std::vector<std::string> split(2);
		split = actual_split(input_str, " | ");
		_input_date.push_back(split[0]);
		_input_value.push_back(split[1]);
	}
}

void	BitcoinExchange::_read_data(std::ifstream &file)
{
	std::string input_str;
	while (std::getline(file,  input_str))
	{
		std::vector<std::string> split(2);
		split = actual_split(input_str, ",");
		_data_date.push_back(split[0]);
		_data_rate.push_back(split[1]);
	}
}

int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

void	BitcoinExchange::_init(std::string input_file)
{
	std::ifstream input, data;
	input.open(input_file.c_str()); data.open("data.csv");
	if (!is_regular_file(input_file.c_str()))
		throw OpenFileError();
	if (input.bad() || data.bad())
		throw OpenFileError();
	_read_input(input);
	_read_data(data);
	input.close(), data.close();
	if (_input_date[0] != "date" || _input_value[0] != "value")
		throw FileFormatError();
}

bool	Chck_date_days(std::vector<std::string> &split_date)
{
	switch (atoi(split_date[1].c_str()))
	{
		case 1: 
			return atoi(split_date[2].c_str()) <= 31;
			break;
		case 2:
			if (atoi(split_date[0].c_str()) % 4 == 0)
				return atoi(split_date[2].c_str()) <= 29;
			else
				return atoi(split_date[2].c_str()) <= 28;
			break;
		case 3: 
			return atoi(split_date[2].c_str()) <= 31;
			break;
		case 4: 
			return atoi(split_date[2].c_str()) <= 30;
			break;
		case 5: 
			return atoi(split_date[2].c_str()) <= 31;
			break;
		case 6: 
			return atoi(split_date[2].c_str()) <= 30;
			break;
		case 7: 
			return atoi(split_date[2].c_str()) <= 31;
			break;
		case 8: 
			return atoi(split_date[2].c_str()) <= 31;
			break;
		case 9: 
			return atoi(split_date[2].c_str()) <= 30;
			break;
		case 10: 
			return atoi(split_date[2].c_str()) <= 31;
			break;
		case 11: 
			return atoi(split_date[2].c_str()) <= 30;
			break;
		case 12: 
			return atoi(split_date[2].c_str()) <= 31;
			break;
		default:
			return false;
			break;
	}
}

void	Chck_date(std::string date)
{
	std::vector<std::string> split_date;
	if (date.size() != 10)
		throw BadInput();
	if (date.find_first_not_of("0123456789-") != std::string::npos)
		throw BadInput();
	split_date = actual_split(date, "-");
	if (split_date.size() != 3)
		throw BadInput();
	if (split_date[0].size() != 4 || split_date[1].size() != 2 || split_date[1].size() != 2)
		throw BadInput();
	if (atoi(split_date[0].c_str()) < 2009 || atoi(split_date[1].c_str()) > 12)
	 	throw BadInput();
	if (!Chck_date_days(split_date))
		throw BadInput();
}

bool	convToInt(std::string value)
{
	long double ldoubleConv = strtold(value.c_str(), NULL);
	if (ldoubleConv > std::numeric_limits<int>::max() || ldoubleConv < std::numeric_limits<int>::min())
		return false;
	return true;
}

void	Chck_value(std::string value)
{
	if (value == "")
		throw NotANum();
	if (value.find_first_not_of("0123456789-.") != std::string::npos)
		throw NotANum();
	if (value[0] == '-')
		throw Underflow();
	if (value[0] == '.')
		throw NotANum();
	if (!convToInt(value))
		throw Overflow();
}

static bool	date_match(std::vector<std::string> &db_date, std::vector<std::string> &req_date)
{
	int cpt = 0;
	for (int i = 0; i < 3 ; i++)
	{
		if (my_int(db_date[i]) < my_int(req_date[i]))
			cpt++;
	}
	if (!cpt)
		return true;
	return false;
}

size_t	BitcoinExchange::_find_best_date(std::string date_req) const
{
	std::vector<std::string> split_input_date = actual_split(date_req, "-");
	size_t i = 1;
	for (; i < _data_date.size(); i++)
	{
		std::vector<std::string> split_data_date = actual_split(_data_date[i], "-");
		if (date_match(split_data_date, split_input_date))
		{
			if (_data_date[i] == date_req)
				return i;
			return i - 1;
		}
	}
	return i - 1;
}

double	BitcoinExchange::_exchange(size_t data_i, size_t input_i) const
{
	return my_double(_data_rate[data_i]) * my_double(_input_value[input_i]);
}

void	BitcoinExchange::trade()
{
	for (size_t i = 1; i < _input_date.size(); i++)
	{
		try
		{
			Chck_date(_input_date[i]);
			Chck_value(_input_value[i]);
			size_t date_index = _find_best_date(_input_date[i]);
			std::cout << _input_date[i] << " => " << _input_value[i];
			std::cout << " = " << _exchange(date_index, i) << std::endl;
		}
		catch (BadInput &e)
		{
			std::cout << e.what() << _input_date[i] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}