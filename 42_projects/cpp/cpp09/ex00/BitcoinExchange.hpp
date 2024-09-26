/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:09:32 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/26 17:25:52 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
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
		std::map<std::string, double> BTC_price;

	public :
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		void parseData(const std::string& date, const std::string& price) const;
		void insertData(const std::ifstream& database);
};
