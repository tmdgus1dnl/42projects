/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:41:23 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/06 17:29:43 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

class GradeTooHighException;
class GradeTooLowException;

class Bureaucrat
{
	private :
		const std::string name;
		int grade;
		Bureaucrat();

	public :
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		const std::string getName() const;
		int getGrade() const;
		void increGrade();
		void decreGrade();
		void chkGrade() const;
		class GradeTooHighException;
		class GradeTooLowException;
};

class Bureaucrat::GradeTooHighException : public std::exception
{
	private :
		std::string msg;

	public :
		GradeTooHighException(const std::string name) throw();
		~GradeTooHighException() throw();
		const char* what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	private :
		std::string msg;

	public :
		GradeTooLowException(const std::string name) throw();
		~GradeTooLowException() throw();
		const char* what() const throw();
};


std::ostream& operator<<(std::ostream& cout, const Bureaucrat& Bcrat);
