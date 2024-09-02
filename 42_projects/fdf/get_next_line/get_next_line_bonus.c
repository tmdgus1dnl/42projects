/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:57:03 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/07 20:42:35 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*gnl_realloc(char *ori_str, char buff[BUFFER_SIZE + 1])
{
	char	*new_str;
	size_t	ori_len;
	size_t	i;

	ori_len = gnl_strlen(ori_str);
	i = 0;
	new_str = (char *)malloc(ori_len + gnl_strlen(buff) + 1);
	if (!new_str)
	{
		free(ori_str);
		return (0);
	}
	while (i < ori_len)
	{
		new_str[i] = ori_str[i];
		i++;
	}
	i = 0;
	while (i < gnl_strlen(buff) + 1)
	{
		new_str[ori_len + i] = buff[i];
		i++;
	}
	free(ori_str);
	return (new_str);
}

static int	get_str(t_list_gnl *new, int fd, char buff[BUFFER_SIZE + 1])
{
	char		*free_str;
	long long	read_len;
	size_t		ret_len;
	size_t		next_len;

	while (!(gnl_strchr(new -> next_str, '\n')))
	{
		read_len = read(fd, buff, BUFFER_SIZE);
		if (read_len == -1)
			return (read_len);
		else if (!read_len)
			break ;
		buff[read_len] = 0;
		new -> next_str = gnl_realloc(new -> next_str, buff);
	}
	if (!(gnl_strchr(new -> next_str, '\n')))
		ret_len = gnl_strlen(new -> next_str);
	else
		ret_len = gnl_strchr(new -> next_str, '\n');
	next_len = gnl_strlen(new -> next_str);
	free_str = new -> next_str;
	new -> ret_str = gnl_substr(new -> next_str, 0, ret_len);
	new -> next_str = gnl_substr(new -> next_str, ret_len, next_len);
	free(free_str);
	return (1);
}

static void	node_free(t_list_gnl **lst)
{
	t_list_gnl	*fron_tmp;
	t_list_gnl	*back_tmp;

	if ((*lst)-> next_str)
		free((*lst)-> next_str);
	fron_tmp = (*lst)-> next;
	back_tmp = (*lst)-> prev;
	free(*lst);
	*lst = back_tmp;
	if (back_tmp)
		(*lst)-> next = fron_tmp;
	if (back_tmp && !(fron_tmp))
		return ;
	*lst = fron_tmp;
	if (*lst)
		(*lst)-> prev = back_tmp;
}

void	gnl_lstclear(t_list_gnl **lst, int fd)
{
	t_list_gnl	*temp;

	temp = *lst;
	while (*lst)
	{
		if ((*lst)-> node_fd == fd && (*lst)-> next)
			node_free(lst);
		*lst = (*lst)-> prev;
	}
	*lst = temp;
	node_free(lst);
}

char	*get_next_line(int fd)
{
	static t_list_gnl	*lst;
	t_list_gnl			*new;
	char				buff[BUFFER_SIZE + 1];
	char				*str;
	int					read_ret;

	if (fd < 0)
		return (0);
	new = gnl_lstnew(fd, &lst);
	if (!new)
		return (0);
	if (!lst)
		gnl_lstadd(&lst, new);
	while (lst -> prev && lst -> node_fd != new -> node_fd)
		lst = lst -> prev;
	gnl_lstadd(&lst, new);
	read_ret = get_str(new, fd, buff);
	str = new -> ret_str;
	while (lst -> next)
		lst = lst -> next;
	if (!(new -> ret_str) || !(new -> next_str))
		read_ret = -1;
	if (read_ret == -1)
		gnl_lstclear(&lst, fd);
	return (str);
}
