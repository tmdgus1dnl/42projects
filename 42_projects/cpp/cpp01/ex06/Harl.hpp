/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:04:15 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/20 17:31:31 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Harl
{
	private :
		std::string filter;
		int filter_index;
		typedef void (Harl::*FuncTable)();
		FuncTable table[4];
		void init_table(FuncTable *table);
		void debug();
		void info();
		void warning();
		void error();
	public :
		Harl(std::string filter);
		~Harl();
		int  get_table_index(std::string level);
		void complain(std::string level);
};
