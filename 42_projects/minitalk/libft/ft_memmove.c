/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:29:02 by seunghan          #+#    #+#             */
/*   Updated: 2023/11/02 18:58:22 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

static unsigned char	*mchk(unsigned char *dst, unsigned char *sc, size_t ct)
{
	size_t	i;

	i = 0;
	while (i < ct)
		i++;
	if (sc < dst)
	{
		while (i > 0)
		{
			dst[i - 1] = sc[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < ct)
		{
			dst[i] = sc[i];
			i++;
		}
	}
	return (dst);
}

void	*ft_memmove(void *dest, void *src, size_t count)
{
	unsigned char	*dst;
	unsigned char	*sc;

	if (dest == 0 && src == 0)
		return (dest);
	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	dst = mchk(dst, sc, count);
	return (dst);
}
