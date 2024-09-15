/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:37:08 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/11 15:53:24 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("shrubbery creation", 145, 137)
{
	this->target = target;
	std::cout << "ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm(other.getName(), other.getSgrade(), other.getEgrade())
{
	*this = other;
	std::cout << "ShrubberyCreationForm copy created" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		this->target = other.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::drawTree() const
{
	std::ofstream outFile(target + "_shrubbery");
	if (!outFile)
	{
		std::cout << "File err" << std::endl;
		exit(1);
	}
	outFile << "                       . . .\n"
             "     .        .  .     ..    .\n"
             "  .                 .         .  .\n"
             "                  .\n"
             "                 .                ..\n"
             "  .          .            .              .\n"
             "  .            '.,        .               .\n"
             "  .              'b      *\n"
             "   .              '$    #.                ..\n"
             "  .    .           $:   #:               .\n"
             "..      .  ..      *#  @):        .   . .\n"
             "             .     :@,@):   ,.**:'   .\n"
             ".      .,         :@@*: ..**'      .   .\n"
             "         '#o.    .:(@'.@*\"'  .\n"
             " .  .       'bq,..:,@@*'   ,*      .  .\n"
             "            ,p$q8,:@)'  .p*'      .\n"
             "     .     '  . '@@Pp@@*'    .  .\n"
             "      .  . ..    Y7'.'     .  .\n"
             "                 :@):.\n"
             "               .:@:'.\n"
             "             .::(@:.\n" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getEgrade())
		throw GradeTooLowException(executor.getName());
	else
		drawTree();
}
