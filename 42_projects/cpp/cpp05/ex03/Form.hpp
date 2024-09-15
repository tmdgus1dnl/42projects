/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:39:43 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/11 17:15:06 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class GradeTooHighException;
class GradeTooLowException;

class Form
{
	private :
		const std::string name;
		bool sign;
		const int signable_G;
		const int executable_G;

	protected :
		Form();

	public :
		Form(std::string name, int signable_g, int executable_g);
		Form(const Form& other);
		Form& operator=(const Form& other);
		virtual ~Form();
		const std::string getName() const;
		bool getSign() const;
		int getSgrade() const;
		int getEgrade() const;
		void chkGrade(int grade) const;
		void beSigned(const Bureaucrat& Bcrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException;
		class GradeTooLowException;
};

class Form::GradeTooHighException : public std::exception
{
	private :
		std::string msg;

	public :
		GradeTooHighException(const std::string name) throw();
		~GradeTooHighException() throw();
		const char* what() const throw();
};

class Form::GradeTooLowException : public std::exception
{
	private :
		std::string msg;

	public :
		GradeTooLowException(const std::string name) throw();
		~GradeTooLowException() throw();
		const char* what() const throw();
};


std::ostream& operator<<(std::ostream& cout, const Form& form);
