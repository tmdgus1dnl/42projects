/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:58:02 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/21 12:13:21 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "noSed.hpp"

int main(int argc, char **argv)
{
	std::string file_name;
	std::string line;
	std::string s1;
	std::string s2;
	size_t		start;

	if (argc != 4)
		return (1);

	file_name = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	std::ifstream inFile(file_name);
	std::ofstream outFile(file_name + ".replace");
	if (!s1.length())
	{
		std::cout << "s1 is empty" << std::endl;
		return (1);
	}
	if (!inFile || !outFile)
	{
		std::cout << "File err" << std::endl;
		return (1);
	}
	while (std::getline(inFile, line))
	{
		start = line.find(s1);
		while (start != std::string::npos)
		{
			line.erase(start, s1.length());
			line.insert(start, s2);
			start = line.find(s1, start + s2.length());
		}
		outFile << line << std::endl;
	}
	return (0);
}
