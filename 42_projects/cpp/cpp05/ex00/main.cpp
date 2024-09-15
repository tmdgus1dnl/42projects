/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:40:24 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/11 15:47:33 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat A("A", 150);
		Bureaucrat B("B", 1);
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		B.decreGrade();
		A.decreGrade();
		std::cout << A << std::endl;
		std::cout << B << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
