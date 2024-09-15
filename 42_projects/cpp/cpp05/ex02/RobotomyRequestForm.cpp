/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:42:53 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/11 15:53:09 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("robotomy request", 72, 45)
{
	this->target = target;
	std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other.getName(), other.getSgrade(), other.getEgrade())
{
	*this = other;
	std::cout << "RobotomyRequestForm copy created" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		this->target = other.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::robotomizeTarget() const
{
	std::srand(std::time(0));
	std::cout << "Drrrrrrrrrrr..." << std::endl;
	if (rand() % 2)
		std::cout << target << " has been robotomized succesfully\n" << std::endl;
	else
		std::cout << target << " robotomization failed..\n" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getEgrade())
		throw GradeTooLowException(executor.getName());
	else
		robotomizeTarget();
}
