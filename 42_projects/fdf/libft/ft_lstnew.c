/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:39:04 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/07 18:47:39 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node -> num = 0;
	new_node -> index = 0;
	new_node -> weight = 0;
	new_node -> gap = 0;
	new_node -> next = 0;
	new_node -> prev = 0;
	return (new_node);
}
