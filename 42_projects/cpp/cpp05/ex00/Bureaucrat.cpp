/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:41:14 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/11 15:44:49 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : 
	name(name),
	grade(grade)
{
	chkGrade();
	std::cout << "Bureaucrat constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
	std::cout << "Bureaucrat copy constructed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->grade = other.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destroyed" << std::endl;
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

void Bureaucrat::chkGrade() const
{
	if (grade < 1)
		throw GradeTooHighException(this->name);
	else if (grade > 150)
		throw GradeTooLowException(this->name);
}

int Bureaucrat::getGrade() const
{
	chkGrade();
	return (this->grade);
}

void Bureaucrat::increGrade()
{
	(this->grade)--;
	try
	{
		chkGrade();
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		(this->grade)++;
	}
}

void Bureaucrat::decreGrade()
{
	(this->grade)++;
	try
	{
		chkGrade();
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		(this->grade)--;
	}
}

//exception

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string name) throw()
{
	this->msg = name + " Grade is too high!";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string name) throw()
{
	this->msg = name + " Grade is too low!";
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (msg.c_str());
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (msg.c_str());
}

std::ostream& operator<<(std::ostream& cout, const Bureaucrat& Bcrat)
{
	cout << Bcrat.getName() << ", bureaucrat grade " << Bcrat.getGrade()
		<< std::endl;
	return (cout);
}
