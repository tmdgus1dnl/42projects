/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:40:24 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/11 17:36:50 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

void cl()
{
	system("leaks -q Intern");
}

int main(void)
{
	Intern intern;
	Form *form;
	form = 0;
	atexit(cl);
	try
	{
		Bureaucrat A("A", 150);
		Bureaucrat B("B", 1);
		std::cout << A << std::endl;
		std::cout << B << std::endl;

		form = intern.makeForm("robotomy request", "Jimmy");
		//form = intern.makeForm("shrubbery creation", "bob");
		std::cout << *form << std::endl;

		if (form)
		{
			A.signForm(*form);
			B.signForm(*form);
			A.executeForm(*form);
			B.executeForm(*form);
		}
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	if (form)
		delete form;
	return (0);
}
