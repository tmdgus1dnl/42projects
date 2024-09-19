/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:33:50 by seunghan          #+#    #+#             */
/*   Updated: 2024/09/18 16:25:53 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int arrI[5] = {1, 2, 3, 4, 5};
	double arrD[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string arrS[5] = {"aa", "bb", "cc", "ee", "ff"};

	iter(arrI, arrSize(arrI), Print);
	iter(arrD, arrSize(arrD), Print);
	iter(arrS, arrSize(arrS), Print);

	return (0);
}
