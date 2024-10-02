/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:17:03 by seunghan          #+#    #+#             */
/*   Updated: 2024/10/01 18:55:09 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange binance;
		BitcoinExchange upbit(binance);
		//binance.printData();
		//upbit.printData();
		binance.exchangeBTC(argv[1]);
		//upbit.exchangeBTC(argv[1]);
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
}
