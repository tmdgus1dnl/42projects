/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:26:22 by seunghan          #+#    #+#             */
/*   Updated: 2024/10/02 18:40:34 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string& expression)
{
	parseExpression(expression);
	this->expression = expression;
}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->numstack = other.getStack();
		this->expression = other.getExpression();
	}
	return (*this);
}

void RPN::parseExpression(const std::string& expression) const
{
	chkSpace(expression);
	chkExpressionValid(expression);
}

void RPN::chkSpace(const std::string& expression) const
{
	bool spaceFlag = false;

	for (std::size_t i = 0; i < expression.size(); ++i)
	{
		if (isspace(expression[i]) == true)
		{
			spaceFlag = true;
			continue;
		}

		if (isdigit(expression[i]) == true || isOper(expression[i]) == true)
		{
			if (isSignNum(expression, i) == true) 
			{
				if (i == 0)
					spaceFlag = true;
				continue;
			}
			if (spaceFlag == true || i == 0)
			{
				spaceFlag = false;
				continue;
			}
			else
				throw std::invalid_argument("Error");
		}
		else
			throw std::invalid_argument("Error");
	}
}

void RPN::chkExpressionValid(const std::string& expression) const
{
	int numCnt = 0;

	for (std::size_t i = 0; i < expression.size(); ++i)
	{
		if (isOper(expression[i]) == true)
		{
			if (isSignNum(expression, i) == true) 
				continue;
			else if (numCnt >= 2)
				numCnt--;
			else
				throw std::invalid_argument("Error");
		}

		if (isdigit(expression[i]) == true)
			numCnt++;
	}

	if (numCnt != 1)
		throw std::invalid_argument("Error");
}

void RPN::operate()
{
	for (std::size_t i = 0; i < expression.size(); ++i)
	{
		if (isspace(expression[i]) == true)
			continue;

		if (isOper(expression[i]) == true)
		{
			if (isSignNum(expression, i) == true) 
			{
				numstack.push(atoi(expression.substr(i, 2).c_str()));
				++i;
				continue;
			}

			doOper(expression[i]);
		}
		
		if (isdigit(expression[i]) == true)
			numstack.push(atoi(expression.substr(i, 1).c_str()));
	}

	std::cout << numstack.top() << std::endl;
}

void RPN::doOper(char oper)
{
	int left, right, result;

	right = numstack.top();
	numstack.pop();
	
	left = numstack.top();
	numstack.pop();

	switch (oper)
	{
		case '+':
			result = left + right;
			break ;
		case '-':
			result = left - right;
			break ;
		case '*':
			result = left * right;
			break ;
		case '/':
			result = left / right;
	}

	numstack.push(result);
}

bool RPN::isOper(char ch) const
{
	if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
		return (true);
	else
		return (false);
}

bool RPN::isSignNum(const std::string& expression, std::size_t i) const
{
	if (i == expression.size() - 1)
		return (false);

	if ((expression[i] == '+' || expression[i] == '-') 
			&& isdigit(expression[i + 1]) == true)
		return (true);
	else
		return (false);
}	

const std::stack<int>& RPN::getStack() const
{
	return (this->numstack);
}

const std::string& RPN::getExpression() const
{
	return (this->expression);
}
