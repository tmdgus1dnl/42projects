/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:16:21 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/08 11:20:48 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atoi(const char *str)
{
	size_t	i;
	int		sub;
	int		temp;
	double	ret;

	i = 0;
	sub = 1;
	ret = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sub = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = str[i] - '0';
		ret = ret * 10 + temp;
		i++;
	}
	if ((str[i] < '0' || str[i] > '9') && ft_strlen(str) != i && str[i] != '\n')
		return (2147483648);
	return (ret * sub);
}
