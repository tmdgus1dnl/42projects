/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:23:27 by seunghan          #+#    #+#             */
/*   Updated: 2023/11/10 15:39:13 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size <= 0)
		return (len);
	while (i + 1 < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (len);
}
