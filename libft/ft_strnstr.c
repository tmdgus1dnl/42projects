/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:21:26 by seunghan          #+#    #+#             */
/*   Updated: 2023/11/08 16:14:46 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lit_count;
	size_t	length;

	i = 0;
	lit_count = ft_strlen(little);
	while ((i < len && big[i]) || !(little[0]))
	{
		if (big[i] == little[0] || !(little[0]))
		{
			length = 1;
			j = 1;
			while (little[0] && little[j] && (i + j < len) && big[i + j])
			{
				if (big[i + j] == little[j])
					length++;
				j++;
			}
			if (lit_count == length || !(little[0]))
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
