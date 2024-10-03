/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:09:16 by seunghan          #+#    #+#             */
/*   Updated: 2024/10/03 13:48:27 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	database.open("data.csv");

	if (database.is_open() == false)
		throw std::runtime_error("Error: could not open file.");

	insertData(database);
}

BitcoinExchange::~BitcoinExchange()
{
	database.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->BTC_price = other.getMap();
	}
	return (*this);
}

const std::map<int, double>& BitcoinExchange::getMap() const
{
	return (this->BTC_price);
}

void BitcoinExchange::parseFirstData(const std::string& line) const
{
	if (line == "date,exchange_rate")
		return ;
	else
		throw std::invalid_argument("Error: database format is incorrect");
}

void BitcoinExchange::parseData(const std::string& date, 
		const std::string& price_str) const
{
	int year, month, day;
	double price_double;
	char delimiter;
	char *ptr;

	if (date.size() != 10)
		throw std::invalid_argument("Error: database format is incorrect");

	price_double = std::strtod(price_str.c_str(), &ptr);
	if (*ptr || ptr == price_str.c_str() || price_double < 0 || price_double > 10000000)
		throw std::invalid_argument("Error: database format is incorrect");

	std::istringstream date_split(date);

	date_split >> year >> delimiter;
	if ((year < 1000 || year > 9999) || delimiter != '-')
		throw std::invalid_argument("Error: database format is incorrect");

	date_split >> month >> delimiter;
	if ((month < 1 || month > 12) || delimiter != '-')
		throw std::invalid_argument("Error: database format is incorrect");

	date_split >> day;
	if ((day >= 1 && day <= 31))
	{
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
			throw std::invalid_argument("Error: database format is incorrect");
		if (month == 2 && year % 4 != 0 && (year % 100 == 0 || year % 400 != 0)
				&& day > 28)
			throw std::invalid_argument("Error: database format is incorrect");
	}
	else
		throw std::invalid_argument("Error: database format is incorrect");
}

void BitcoinExchange::insertData(std::ifstream& database)
{
	std::string line, date, price;
	size_t delimiter_pos;

	std::getline(database, line);
	parseFirstData(line);

	while (std::getline(database, line))
	{
		delimiter_pos = line.find(',');
		date = line.substr(0, delimiter_pos);
		price = line.substr(delimiter_pos + 1);

		parseData(date, price);

		BTC_price.insert(std::pair<int, double>(dateToInt(date), 
					std::strtod(price.c_str(), 0)));
	}
}

void BitcoinExchange::parseFirstInput(const std::string& line) const
{
	if (line == "date | value")
		return ;
	else
		throw std::invalid_argument("Error: input format is incorrect");
}

void BitcoinExchange::parseInput(const std::string& date, 
		const std::string& amount_str) const
{
	int year, month, day;
	double amount_double;
	char delimiter;
	char *ptr;

	if (date.size() != 10)
		throw std::invalid_argument("Error: bad input");

	amount_double = std::strtod(amount_str.c_str(), &ptr);
	if (*ptr || ptr == amount_str.c_str())
		throw std::invalid_argument("Error: bad input");

	std::istringstream date_split(date);

	date_split >> year >> delimiter;
	if ((year < 1000 || year > 9999) || delimiter != '-')
		throw std::invalid_argument("Error: bad input");

	date_split >> month >> delimiter;
	if ((month < 1 || month > 12) || delimiter != '-')
		throw std::invalid_argument("Error: bad input");

	date_split >> day;
	if ((day >= 1 && day <= 31))
	{
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
			throw std::invalid_argument("Error: bad input");
		if (month == 2 && year % 4 != 0 && (year % 100 == 0 || year % 400 != 0)
				&& day > 28)
			throw std::invalid_argument("Error: bad input");
	}
	else
		throw std::invalid_argument("Error: bad input");

	if (amount_double < 0)
		throw std::invalid_argument("Error: not a positive number.");
	if (amount_double > 22000000)
		throw std::invalid_argument("Error: too large a number.");
}

void BitcoinExchange::exchangeBTC(const std::string& input_filename) const
{
	std::ifstream input(input_filename.c_str());

	if (input.is_open() == false)
		throw std::runtime_error("Error: could not open file.");

	std::string line, date, amount;
	size_t delimiter_pos;

	std::getline(input, line);
	parseFirstInput(line);

	while (std::getline(input, line))
	{
		delimiter_pos = line.find(" | ");
		date = line.substr(0, delimiter_pos);
		amount = line.substr(delimiter_pos + 3);

		try
		{
			parseInput(date, amount);
			printExchangedBTC(date, amount);
		}

		catch (std::exception& e)
		{
			if (e.what() == std::string("Error: bad input"))
				std::cout << e.what() << " => " << line << std::endl;
			else
				std::cout << e.what() << std::endl;
		}
	}

	input.close();
}

void BitcoinExchange::printExchangedBTC(const std::string& date, 
		const std::string& amount_str) const
{
	double amount_double;
	char* ptr;

	amount_double = std::strtod(amount_str.c_str(), &ptr);

	map_iter it = getClosestDate(date);
	std::cout << date << " => " << amount_str << " = " 
		<< std::setprecision(10) << (it->second) * amount_double << std::endl;
}

BitcoinExchange::map_iter BitcoinExchange::getClosestDate(const std::string& date) const
{
	int date_int;

	date_int = dateToInt(date);
	map_iter it = BTC_price.begin();
	if (date_int < it->first)
		throw std::invalid_argument("Error: cannot find valid date.");

	while (it != BTC_price.end())
	{
		if (date_int < it->first)
			break ;
		++it;
	}
	
	return (--it);
}

int BitcoinExchange::dateToInt(const std::string& date) const
{
	int year, month, day;
	char delimiter;

	std::istringstream date_split(date);

	date_split >> year >> delimiter >> month >> delimiter >> day;

	return (year * 10000 + month * 100 + day);
}	

void BitcoinExchange::printData() const
{
	for (map_iter it = BTC_price.begin(); it != BTC_price.end(); ++it)
		std::cout << "Date : " << it->first << ", price : " 
			<< std::setprecision(10) << it->second << std::endl;
}
