/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:49:03 by seunghan          #+#    #+#             */
/*   Updated: 2023/10/23 11:56:57 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	*ft_memchr(void *dest, int c, size_t count)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)dest;
	while (i < count)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (0);
}
