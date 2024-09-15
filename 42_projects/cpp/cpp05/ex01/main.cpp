/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:40:24 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/10 16:16:39 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat A("A", 150);
		Bureaucrat B("B", 1);
		std::cout << A << std::endl;
		std::cout << B << std::endl;

		Form D1("Document1", 8, 8);
		Form D2("Document2", 1, 1);
		std::cout << D1 << std::endl;
		std::cout << D2 << std::endl;

		A.signForm(D1);
		B.signForm(D1);
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
