/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:09:32 by seunghan          #+#    #+#             */
/*   Updated: 2024/10/02 11:12:15 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <stdexcept>
#include <exception>
#include <cstdlib>
#include <cctype>
#include <cmath>

class BitcoinExchange
{
	private :
		std::map<int, double> BTC_price;
		std::ifstream database;

	public :
		typedef std::map<int, double>::const_iterator map_iter;
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		const std::map<int, double>& getMap() const;
		void parseFirstData(const std::string& line) const;
		void parseData(const std::string& date, const std::string& price) const;
		void insertData(std::ifstream& database);
		void parseFirstInput(const std::string& line) const;
		void parseInput(const std::string& date, const std::string& amount_str) const;
		void printExchangedBTC(const std::string& date, const std::string& amount_str) const;
		void exchangeBTC(const std::string& input_filename) const;
		map_iter getClosestDate(const std::string& date) const;
		int dateToInt(const std::string& date) const;
		void printData();
};
