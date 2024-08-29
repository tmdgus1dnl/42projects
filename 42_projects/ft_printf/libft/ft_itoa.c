/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:29:33 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/12 12:25:10 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	n_chk(long long n, int *siz)
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

static int	put_str(char *asc_arr, int size)
{
	size_t	i;

	i = 0;
	while (asc_arr[i])
		i++;
	if (write(1, asc_arr, i) == -1)
	{
		free(asc_arr);
		return (0);
	}
	free(asc_arr);
	return (size);
}

int	ft_itoa(int n)
{
	char		*asc_arr;
	int			size;
	int			i;
	long long	div;

	size = 1;
	div = n_chk(n, &size);
	asc_arr = (char *)malloc(size * sizeof(char));
	if (!(asc_arr))
		return (-1);
	i = size - 1;
	asc_arr[i] = 0;
	while (i > 0)
	{
		asc_arr[i - 1] = div % 10 + '0';
		div = div / 10;
		i--;
	}
	if (n < 0)
		asc_arr[0] = '-';
	else if (!(n))
		asc_arr[0] = '0';
	size = put_str(asc_arr, size);
	return (size - 1);
}
