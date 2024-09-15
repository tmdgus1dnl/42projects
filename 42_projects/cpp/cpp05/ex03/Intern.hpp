/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:45:51 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/11 17:28:38 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private :
		std::string names[3];
		Form* (Intern::*funcTable[3]) (const std::string& target) const;

	public :
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
		Form* makeForm(const std::string& name, const std::string& target) const;
		Form* makeShrubbery(const std::string& target) const;
		Form* makeRobotomy(const std::string& target) const;
		Form* makePresidential(const std::string& target) const;
		void emptyFunc() const;
};
