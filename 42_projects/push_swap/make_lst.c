/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:53:58 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/31 11:28:23 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_cmd	*make_cmd_set(void)
{
	t_list_cmd	*cmd_set;

	cmd_set = (t_list_cmd *)malloc(sizeof(t_list_cmd));
	if (!cmd_set)
		exit(1);
	cmd_set -> ra_flag = 0;
	cmd_set -> rra_flag = 0;
	cmd_set -> rb_flag = 0;
	cmd_set -> rrb_flag = 0;
	return (cmd_set);
}

static int	dup_chk(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack -> next;
		while (temp)
		{
			if (stack -> num == temp -> num)
				return (-1);
			temp = temp -> next;
		}
		stack = stack -> next;
	}
	return (1);
}

static int	ft_countword(const char *s, char c)
{
	size_t	word;
	size_t	i;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			word++;
		i++;
	}
	if (s[0] != c && s[0] != '\0')
		word++;
	return (word);
}

static void	split_words(t_list **stack_a, int argc, char **argv)
{
	t_list	*new;
	size_t	i;
	char	**numbs;

	i = 0;
	numbs = ft_split(argv[argc - 1], ' ');
	if (!numbs)
		exit(1);
	while (numbs[i])
		i++;
	while (i)
	{
		new = ft_lstnew();
		if (!new)
			exit(1);
		ft_lstadd_back(stack_a, new);
		new -> num = ft_atoi(numbs[i - 1]);
		i--;
	}
	while (numbs[i])
		free(numbs[i++]);
	free(numbs);
}

void	make_lst(t_list **stack_a, t_list **stack_b, int argc, char **argv)
{
	t_list	*new;

	*stack_a = 0;
	*stack_b = 0;
	while (argc != 1)
	{
		if (ft_countword(argv[argc - 1], ' ') == 1)
		{
			new = ft_lstnew();
			if (!new)
				exit(1);
			ft_lstadd_back(stack_a, new);
			new -> num = ft_atoi(argv[argc - 1]);
		}
		else
			split_words(stack_a, argc, argv);
		argc--;
	}
	if (dup_chk(*stack_a) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	get_num(*stack_a);
}
