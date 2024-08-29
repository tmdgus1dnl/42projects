/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:28:33 by seunghan          #+#    #+#             */
/*   Updated: 2023/11/07 12:17:55 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

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
	*lst = head;
}
