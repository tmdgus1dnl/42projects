/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:15:00 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/31 11:40:02 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strchr(const char *str, int c)
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

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_s;
	unsigned int	i;

	i = gnl_strlen(s);
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

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

t_list_gnl	*gnl_lstnew(int fd, t_list_gnl **lst)
{
	t_list_gnl	*new_node;

	new_node = (t_list_gnl *)malloc(sizeof(t_list_gnl));
	if (!new_node)
	{
		if (*lst)
		{
			if ((*lst)-> node_fd == fd)
				gnl_lstclear(lst, fd);
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

void	gnl_lstadd(t_list_gnl **lst, t_list_gnl *new)
{
	size_t	next_len;

	if (!(new) || (*lst) == new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	next_len = gnl_strlen((*lst)-> next_str);
	if ((*lst)-> node_fd == new -> node_fd)
		new -> next_str = gnl_substr((*lst)-> next_str, 0, next_len);
	while ((*lst)-> next)
		*lst = (*lst)-> next;
	(*lst)-> next = new;
	new -> prev = *lst;
}
