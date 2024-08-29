/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:29:33 by seunghan          #+#    #+#             */
/*   Updated: 2023/12/05 18:25:29 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	n_chk(unsigned int n, int *siz)
{
	unsigned int	div;
	unsigned int	temp_div;

	if (n == 0)
		(*siz)++;
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

int	ft_utoa(unsigned int n)
{
	char			*asc_arr;
	int				size;
	int				i;
	unsigned int	div;

	size = 1;
	div = n_chk(n, &size);
	asc_arr = (char *)malloc(size * sizeof(char));
	if (!(asc_arr))
		return (-1);
	i = size - 1;
	asc_arr[i] = 0;
	while (i > 0)
	{
		asc_arr[i - 1] = div % 10 + 48;
		div = div / 10;
		i--;
	}
	if (!(n))
		asc_arr[0] = '0';
	size = put_str(asc_arr, size);
	return (size - 1);
}
