/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:24:33 by seunghan          #+#    #+#             */
/*   Updated: 2024/10/02 17:34:08 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	try
	{
		RPN rpn(argv[1]);
		rpn.operate();
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}

	return (0);
}
