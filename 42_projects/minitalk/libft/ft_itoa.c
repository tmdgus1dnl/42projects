/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:29:33 by seunghan          #+#    #+#             */
/*   Updated: 2023/11/02 18:53:07 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static long long	n_chk(long long n, size_t *siz)
{
	long long	div;
	long long	temp_div;

	if (n <= 0)
	{
		div = -n;
		(*siz)++;
	}
	else
		div = n;
	temp_div = div;
	while (temp_div != 0)
	{
		temp_div = temp_div / 10;
		(*siz)++;
	}
	return (div);
}

char	*ft_itoa(int n)
{
	char		*asc_arr;
	size_t		size;
	int			i;
	long long	div;

	size = 1;
	div = n_chk((long long)n, &size);
	asc_arr = (char *)malloc(size * sizeof(char));
	if (!(asc_arr))
		return (0);
	i = size - 1;
	asc_arr[i] = 0;
	while (i > 0)
	{
		asc_arr[i - 1] = div % 10 + 48;
		div = div / 10;
		i--;
	}
	if (n < 0)
		asc_arr[0] = '-';
	else if (!(n))
		asc_arr[0] = '0';
	return (asc_arr);
}
