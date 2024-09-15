/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:41:00 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/11 15:43:29 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : signable_G(0), executable_G(0) {}

AForm::AForm(std::string name, int signable_g, int executable_g) :
	name(name),
	signable_G(signable_g),
	executable_G(executable_g)
{
	chkGrade(signable_G);
	chkGrade(executable_G);
	this->sign = false;
	std::cout << "AForm created" << std::endl;
}

AForm::AForm(const AForm& other) :
	name(other.getName()),
	signable_G(other.getSgrade()),
	executable_G(other.getEgrade())
{
	*this = other;
	std::cout << "AForm copy created" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->sign = other.sign;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destroyed" << std::endl;
}

const std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getSign() const
{
	return (this->sign);
}

int AForm::getSgrade() const
{
	return (this->signable_G);
}

int AForm::getEgrade() const
{
	return (this->executable_G);
}

void AForm::chkGrade(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException(this->name);
	else if (grade > 150)
		throw GradeTooLowException(this->name);
}

void AForm::beSigned(const Bureaucrat& Bcrat)
{
	if (Bcrat.getGrade() <= signable_G)
		this->sign = true;
	else
		throw GradeTooLowException(Bcrat.getName());
}

//exception

AForm::GradeTooHighException::GradeTooHighException(const std::string name) throw()
{
	this->msg = name + " Grade is too high!\n";
}

AForm::GradeTooLowException::GradeTooLowException(const std::string name) throw()
{
	this->msg = name + " Grade is too low!\n";
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char* AForm::GradeTooHighException::what() const throw()
{
	return (msg.c_str());
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return (msg.c_str());
}

std::ostream& operator<<(std::ostream& cout, const AForm& form)
{
	cout << form.getName() << "\n" << "signature : " << form.getSign()
		<< "\n" << "signable_grade : " << form.getSgrade()
		<< "\n" << "executable_grade : " << form.getEgrade()
		<< "\n";
	return (cout);
}
