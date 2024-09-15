/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:27:50 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/11 15:53:30 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("presidential pardon", 25, 5)
{
	this->target = target;
	std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm(other.getName(), other.getSgrade(), other.getEgrade())
{
	*this = other;
	std::cout << "PresidentialPardonForm copy created" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		this->target = other.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void PresidentialPardonForm::pardonTarget() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox "
		<< std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getEgrade())
		throw GradeTooLowException(executor.getName());
	else
		pardonTarget();
}
