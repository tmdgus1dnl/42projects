/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:15:14 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/16 17:45:43 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
size_t		gnl_strchr(const char *s, int c);
size_t		gnl_strlen(const char *s);
char		*gnl_substr(char const *s, unsigned int start, size_t len);

typedef struct s_list_gnl
{
	char				*ret_str;
	char				*next_str;
	int					node_fd;
	struct s_list_gnl	*next;
	struct s_list_gnl	*prev;
}	t_list_gnl;

void		gnl_lstadd(t_list_gnl **lst, t_list_gnl *new);
t_list_gnl	*gnl_lstnew(int fd, t_list_gnl **lst);
void		gnl_lstclear(t_list_gnl **lst, int fd);

#endif
