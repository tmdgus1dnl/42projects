/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:41:00 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/10 16:16:37 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : signable_G(0), executable_G(0) {}

Form::Form(std::string name, int signable_g, int executable_g) :
	name(name),
	signable_G(signable_g),
	executable_G(executable_g)
{
	chkGrade(signable_G);
	chkGrade(executable_G);
	this->sign = false;
	std::cout << "Form created" << std::endl;
}

Form::Form(const Form& other) :
	signable_G(other.getSgrade()),
	executable_G(other.getEgrade())
{
	*this = other;
	std::cout << "Form copy created" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->sign = other.sign;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destroyed" << std::endl;
}

const std::string Form::getName() const
{
	return (this->name);
}

bool Form::getSign() const
{
	return (this->sign);
}

int Form::getSgrade() const
{
	return (this->signable_G);
}

int Form::getEgrade() const
{
	return (this->executable_G);
}

void Form::chkGrade(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException(this->name);
	else if (grade > 150)
		throw GradeTooLowException(this->name);
}

void Form::beSigned(const Bureaucrat& Bcrat)
{
	if (Bcrat.getGrade() <= signable_G)
		this->sign = true;
	else
		throw GradeTooLowException(Bcrat.getName());
}

//exception

Form::GradeTooHighException::GradeTooHighException(const std::string name) throw()
{
	this->msg = name + " Grade is too high!";
}

Form::GradeTooLowException::GradeTooLowException(const std::string name) throw()
{
	this->msg = name + " Grade is too low!";
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Form::GradeTooHighException::what() const throw()
{
	return (msg.c_str());
}

const char* Form::GradeTooLowException::what() const throw()
{
	return (msg.c_str());
}

std::ostream& operator<<(std::ostream& cout, const Form& form)
{
	cout << form.getName() << "\n" << "signature : " << form.getSign()
		<< "\n" << "signable_grade : " << form.getSgrade()
		<< "\n" << "executable_grade : " << form.getEgrade()
		<< "\n";
	return (cout);
}
