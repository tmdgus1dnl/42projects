/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:49:53 by seunghan          #+#    #+#             */
/*   Updated: 2023/11/08 12:03:26 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strchr(const char *str, int c)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)str;
	while (ptr[i])
	{
		if ((unsigned char)c == ptr[i])
			return ((char *)ptr + i);
		i++;
	}
	if ((unsigned char)c == 0)
		return ((char *)ptr + i);
	return (0);
}
