/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:32:30 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/15 16:16:27 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t c)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < c && (str1[i] || str2[j]))
	{
		if (str1[i] != str2[j])
			return (str1[i] - str2[j]);
		i++;
		j++;
	}
	return (0);
}
