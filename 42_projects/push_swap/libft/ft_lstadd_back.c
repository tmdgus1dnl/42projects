/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:28:33 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/03 12:06:01 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;
	size_t	idx;

	if (!(new))
		return ;
	head = *lst;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while ((*lst)-> next)
		*lst = (*lst)-> next;
	(*lst)-> next = new;
	idx = (*lst)-> index + 1;
	new -> index = idx;
	new -> prev = *lst;
	*lst = head;
}
