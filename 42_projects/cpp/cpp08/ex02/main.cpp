/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:31:36 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/25 16:02:12 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	std::cout << "pushed 5" << std::endl;
	mstack.push(5);
	std::cout << "pushed 17" << std::endl;
	mstack.push(17);

	std::cout << "stack top : " << mstack.top() << std::endl;
	std::cout << "popped" << std::endl;
	mstack.pop();
	std::cout << "stack top : " << mstack.top() << std::endl;
	std::cout << "stack size : " << mstack.size() << std::endl;
	std::cout << "\npushed 3" << std::endl;
	mstack.push(3);
	std::cout << "pushed 5" << std::endl;
	mstack.push(5);
	std::cout << "pushed 737" << std::endl;
	mstack.push(737);
	std::cout << "pushed 1" << std::endl;
	mstack.push(1);
	std::cout << "pushed 21" << std::endl;
	mstack.push(21);
	std::cout << "pushed 55" << std::endl;
	mstack.push(55);
	std::cout << "pushed 77\n" << std::endl;
	mstack.push(77);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(mstack);

	std::cout << "\nstack top : " << mstack.top() << std::endl;
	std::cout << "stack size : " << mstack.size() << std::endl;
	std::cout << "copy stack top : " << s.top() << std::endl;
	std::cout << "copy stack size : " << s.size() << std::endl;

	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	lst.pop_back();
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(1);
	lst.push_back(21);
	lst.push_back(55);
	lst.push_back(77);
	
	std::list<int>::iterator itl = lst.begin();
	std::list<int>::iterator itle = lst.end();
	++itl;
	--itl;
	
	std::cout << "\n";
	while (itl != itle)
	{
		std::cout << *itl << std::endl;
		++itl;
	}

	return (0);
}
