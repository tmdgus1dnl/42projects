/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:29:33 by seunghan          #+#    #+#             */
/*   Updated: 2023/12/05 18:18:28 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	n_chk(unsigned int n, int *siz)
{
	unsigned int	div;
	unsigned int	temp_div;

	*siz = 1;
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
		temp_div = temp_div / 16;
		(*siz)++;
	}
	return (div);
}

static int	put_str(char *asc_arr, int size, int n)
{
	size_t	i;

	i = 0;
	while (asc_arr[i])
		i++;
	if (!(n))
		asc_arr[0] = '0';
	if (write(1, asc_arr, i) == -1)
	{
		free(asc_arr);
		return (0);
	}
	free(asc_arr);
	return (size);
}

int	ft_utoh(unsigned int n, char ch)
{
	char		*asc_arr;
	char		*hex;
	int			size;
	int			i;
	size_t		div;

	hex = "0123456789abcdef";
	div = n_chk(n, &size);
	asc_arr = (char *)malloc(size * sizeof(char));
	if (!(asc_arr))
		return (-1);
	i = size - 1;
	asc_arr[i] = 0;
	while (i > 0)
	{
		if (ch == 'X' && (hex[div % 16] >= 'a' && hex[div % 16] <= 'z'))
			asc_arr[i - 1] = hex[div % 16] - 32;
		else
			asc_arr[i - 1] = hex[div % 16];
		div = div / 16;
		i--;
	}
	size = put_str(asc_arr, size, n);
	return (size - 1);
}
