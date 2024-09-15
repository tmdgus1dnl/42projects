/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:45:56 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/11 17:28:37 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	names[0] = "shrubbery creation";
	names[1] = "robotomy request";
	names[2] = "presidential pardon";
	funcTable[0] = &Intern::makeShrubbery;
	funcTable[1] = &Intern::makeRobotomy;
	funcTable[2] = &Intern::makePresidential;
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern& other)
{
	*this = other;
	std::cout << "Intern copy created" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	other.emptyFunc();
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern deleted" << std::endl;
}

Form* Intern::makeForm(const std::string& name, const std::string& target) const
{
	for (int i = 0; i < 3; ++i)
	{
		if ((this->names)[i] == name)
		{
			return ((this->*funcTable[i])(target));
		}
	}
	std::cout << name << " is not a valid Form name!" << std::endl;
	return (0);
}

Form* Intern::makeShrubbery(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}

Form* Intern::makeRobotomy(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}

Form* Intern::makePresidential(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}

void Intern::emptyFunc() const {}
