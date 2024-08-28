/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:57:03 by seunghan          #+#    #+#             */
/*   Updated: 2023/12/03 16:14:07 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_realloc(char *ori_str, char buff[BUFFER_SIZE + 1])
{
	char	*new_str;
	size_t	ori_len;
	size_t	i;

	ori_len = ft_strlen(ori_str);
	i = 0;
	new_str = (char *)malloc(ori_len + ft_strlen(buff) + 1);
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
	while (i < ft_strlen(buff) + 1)
	{
		new_str[ori_len + i] = buff[i];
		i++;
	}
	free(ori_str);
	return (new_str);
}

static int	get_str(t_list *new, int fd, char buff[BUFFER_SIZE + 1])
{
	char		*free_str;
	long long	read_len;
	size_t		ret_len;
	size_t		next_len;

	while (!(ft_strchr(new -> next_str, '\n')))
	{
		read_len = read(fd, buff, BUFFER_SIZE);
		if (read_len == -1)
			return (read_len);
		else if (!read_len)
			break ;
		buff[read_len] = 0;
		new -> next_str = ft_realloc(new -> next_str, buff);
	}
	if (!(ft_strchr(new -> next_str, '\n')))
		ret_len = ft_strlen(new -> next_str);
	else
		ret_len = ft_strchr(new -> next_str, '\n');
	next_len = ft_strlen(new -> next_str);
	free_str = new -> next_str;
	new -> ret_str = ft_substr(new -> next_str, 0, ret_len);
	new -> next_str = ft_substr(new -> next_str, ret_len, next_len);
	free(free_str);
	return (1);
}

static void	node_free(t_list **lst)
{
	t_list	*fron_tmp;
	t_list	*back_tmp;

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

void	ft_lstclear(t_list **lst, int fd)
{
	t_list	*temp;

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
	static t_list	*lst;
	t_list			*new;
	char			buff[BUFFER_SIZE + 1];
	char			*str;
	int				read_ret;

	if (fd < 0)
		return (0);
	new = ft_lstnew(fd, &lst);
	if (!new)
		return (0);
	if (!lst)
		ft_lstadd(&lst, new);
	while (lst -> prev && lst -> node_fd != new -> node_fd)
		lst = lst -> prev;
	ft_lstadd(&lst, new);
	read_ret = get_str(new, fd, buff);
	str = new -> ret_str;
	while (lst -> next)
		lst = lst -> next;
	if (!(new -> ret_str) || !(new -> next_str))
		read_ret = -1;
	if (read_ret == -1)
		ft_lstclear(&lst, fd);
	return (str);
}
