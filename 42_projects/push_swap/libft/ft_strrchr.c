/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:07:29 by seunghan          #+#    #+#             */
/*   Updated: 2023/11/08 12:49:11 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)str;
	i = ft_strlen(str);
	while (i && (unsigned char)c != ptr[i])
		i--;
	if (ptr[i] == (unsigned char)c)
		return ((char *)ptr + i);
	return (0);
}
