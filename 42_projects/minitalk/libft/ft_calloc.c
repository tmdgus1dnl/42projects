/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:37:11 by seunghan          #+#    #+#             */
/*   Updated: 2023/11/14 17:31:10 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*arr;

	if (size && num > ~(size_t)0 / size)
		return (NULL);
	arr = malloc(num * size);
	if (!(arr))
		return (0);
	ft_bzero(arr, num * size);
	return (arr);
}
