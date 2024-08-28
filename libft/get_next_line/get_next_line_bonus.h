/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:15:14 by seunghan          #+#    #+#             */
/*   Updated: 2023/11/30 16:36:29 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

typedef struct s_list
{
	char			*ret_str;
	char			*next_str;
	int				node_fd;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void	ft_lstadd(t_list **lst, t_list *new);
t_list	*ft_lstnew(int fd, t_list **lst);
void	ft_lstclear(t_list **lst, int fd);

#endif
