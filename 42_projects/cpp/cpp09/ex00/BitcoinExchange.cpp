/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:09:16 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/26 17:55:26 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream database("data.scv");

	if (database.is_open() == false)
		throw std::runtime_error("Error: could not open database.");

	insertData(database);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other);

void BitcoinExchange::parseData(const std::string& date, const std::string& price_str) const
{
	int year, month, day;
	double price_double;
	char delimiter;
	char *ptr;

	if (date.size() != 10)
		throw std::invalid_argument("Error: database format is incorrect");

	/*for (int i = 0; i < price.size(); ++i)
	{
		if (std::is_digit(price[i]) == false)
			throw std::invalid_argument("Error: database format is incorrect");
	}*/

	price_double = std::strtod(price_str, &ptr);
	if (ptr || price_double < 0 || std::isinf(price_double))
		throw std::invalid_argument("Error: database format is incorrect");

	std::istringstream date_split(date);

	date_split >> year >> delimiter;
	if ((year < 1000 && year > 9999) || delimiter != '-')
		throw std::invalid_argument("Error: database format is incorrect");

	date_split >> month >> delimiter;
	if ((month < 1 && month > 12) || delimiter != '-')
		throw std::invalid_argument("Error: database format is incorrect");

	date_split >> day >> delimiter;
	if ((day < 1 && day > 31))
	{
		if (delimiter != '-')
			throw std::invalid_argument("Error: database format is incorrect");
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
			throw std::invalid_argument("Error: database format is incorrect");
		if (month == 2 && year % 4 != 0 && (year % 100 == 0 || year % 400 != 0)
				&& day > 28)
			throw std::invalid_argument("Error: database format is incorrect");
	}
	else
		throw std::invalid_argument("Error: database format is incorrect");
}

void BitcoinExchange::insertData(const std::ifstream& database)
{
	std::string line, date, price;
	size_t delimiter_pos;
	char* ptr;

	while (std::getline(database, line))
	{
		delimiter_pos = line.find(',');
		date = line.substr(0, delimiter_pos);
		price = line.substr(delimiter_pos + 1);

		parseData(date, price);

		BTC_price.insert(std::pair<std::string, double>(date, std::strtod(price, &ptr)));
	}
}
