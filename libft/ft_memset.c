/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:39:05 by seunghan          #+#    #+#             */
/*   Updated: 2023/10/23 12:08:56 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	*ft_memset(void *dest, int c, size_t count)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)dest;
	while (i < count)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
