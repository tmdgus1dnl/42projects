/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:40:24 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/11 15:58:57 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat A("A", 150);
		Bureaucrat B("B", 1);
		std::cout << A << std::endl;
		std::cout << B << std::endl;

		ShrubberyCreationForm D1("Jimmy");
		RobotomyRequestForm D2("Bob");
		PresidentialPardonForm D3("Robert");
		std::cout << D1 << std::endl;
		std::cout << D2 << std::endl;
		std::cout << D3 << std::endl;

		/*A.signForm(D1);
		B.signForm(D1);
		A.executeForm(D1);
		B.executeForm(D1);*/
		/*A.signForm(D2);
		B.signForm(D2);
		A.executeForm(D2);
		B.executeForm(D2);*/
		A.signForm(D3);
		B.signForm(D3);
		A.executeForm(D3);
		B.executeForm(D3);
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
