/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:33:57 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/25 19:19:20 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack() {}
		~MutantStack() {}
		MutantStack(const MutantStack& other) : std::stack<T>(other)
		{
			*this = other;
		}
		MutantStack& operator=(const MutantStack&)
		{
			return (*this);
		}
		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}
		typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin()
		{
			return (this->c.rbegin());
		}
		reverse_iterator rend()
		{
			return (this->c.rend());
		}
};
