/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:15:00 by seunghan          #+#    #+#             */
/*   Updated: 2023/11/30 17:59:42 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strchr(const char *str, int c)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)str;
	if (!ptr)
		return (0);
	while (ptr[i])
	{
		if ((unsigned char)c == ptr[i])
		{
			i++;
			return (i);
		}
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_s;
	unsigned int	i;

	i = ft_strlen(s);
	if (!i || start == i)
		return (0);
	if (len + start > i && start < i)
	{
		len = i;
		len = len - start;
	}
	sub_s = (char *)malloc(len * sizeof(char) + 1);
	if (!sub_s)
		return (0);
	i = 0;
	while (i < len && s[start])
	{
		sub_s[i] = s[start];
		i++;
		start++;
	}
	sub_s[i] = 0;
	return (sub_s);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

t_list	*ft_lstnew(int fd, t_list **lst)
{
	t_list		*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
	{
		if (*lst)
		{
			if ((*lst)-> node_fd == fd)
				ft_lstclear(lst, fd);
		}
		return (0);
	}
	new_node -> node_fd = fd;
	new_node -> ret_str = 0;
	new_node -> next_str = 0;
	new_node -> prev = 0;
	new_node -> next = 0;
	return (new_node);
}

void	ft_lstadd(t_list **lst, t_list *new)
{
	size_t	next_len;

	if (!(new) || (*lst) == new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	next_len = ft_strlen((*lst)-> next_str);
	if ((*lst)-> node_fd == new -> node_fd)
		new -> next_str = ft_substr((*lst)-> next_str, 0, next_len);
	while ((*lst)-> next)
		*lst = (*lst)-> next;
	(*lst)-> next = new;
	new -> prev = *lst;
}
