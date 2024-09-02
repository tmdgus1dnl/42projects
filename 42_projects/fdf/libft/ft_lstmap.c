/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:09:39 by seunghan          #+#    #+#             */
/*   Updated: 2023/11/14 17:29:42 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*newlst;
	void	*tmp_cont;

	if (!(f) || !(del))
		return (0);
	newlst = 0;
	while (lst)
	{
		tmp_cont = f(lst -> content);
		new_node = ft_lstnew(tmp_cont);
		ft_lstadd_back(&newlst, new_node);
		if (!(new_node) || !(tmp_cont))
		{
			del(tmp_cont);
			ft_lstclear(&newlst, del);
			return (0);
		}
		lst = lst -> next;
	}
	return (newlst);
}
