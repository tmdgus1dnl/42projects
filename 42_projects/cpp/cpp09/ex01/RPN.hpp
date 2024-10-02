/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:26:06 by seunghan          #+#    #+#             */
/*   Updated: 2024/10/02 18:40:47 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

class RPN
{
	private :
		std::stack<int> numstack;
		std::string expression;
		RPN();

	public :
		RPN(const std::string& expression);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		void parseExpression(const std::string& expression) const;
		void chkSpace(const std::string& expression) const;
		void chkExpressionValid(const std::string& expression) const;
		void operate();
		void doOper(char oper);
		bool isOper(char ch) const;
		bool isSignNum(const std::string& expression, std::size_t i) const;
		const std::stack<int>& getStack() const;
		const std::string& getExpression() const;
};
