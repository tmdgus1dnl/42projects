/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:31:03 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/18 18:27:45 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void cl()
{
	system("leaks -q Array");
}

int main(void)
{
	atexit(cl);
	try
	{
		Array<int> arrI(10);
		Array<double> arrD(10);
		Array<std::string> arrS(10);
		Array<int> A(5);
		Array<int> B(10);
		Array<int> arrEmpty;

		try
		{
			arrI[0] = 100;
			arrI[1] = 200;
			arrD[2] = 2.22;
			arrD[3] = 9.99;
			arrS[4] = "im here";
			arrS[5] = "im here too";
			A[0] = 1;
			A[1] = 2;
			A[2] = 3;
			B[0] = 5;
			B[1] = 6;
			B[2] = 7;
			B[9] = 10;
			A = B;
			//arrEmpty[100] = 5;
		}

		catch (std::exception& e)
		{
			std::cout << "\nindex out of range\n" << std::endl;
		}


		try
		{
			std::cout << arrI[0] << std::endl;
			std::cout << arrI[1] << std::endl;
			std::cout << arrD[2] << std::endl;
			std::cout << arrD[3] << std::endl;
			std::cout << arrS[4] << std::endl;
			std::cout << arrS[5] << std::endl;
			std::cout << A[0] << std::endl;
			std::cout << A[9] << std::endl;
			std::cout << B[0] << std::endl;
			std::cout << B[1] << std::endl;
			std::cout << B[2] << std::endl;
			//std::cout << arrEmpty[0] << std::endl;
		}

		catch (std::exception& e)
		{
			std::cout << "\nindex out of range\n" << std::endl;
		}

	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		exit(1);
	}

	return (0);
}
