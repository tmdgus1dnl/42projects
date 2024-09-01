/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:04:18 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/22 14:28:20 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_max_min(t_list *stack, long *max_num, long *min_num)
{
	t_list	*temp;

	temp = stack;
	if (max_num)
	{
		*max_num = stack -> num;
		while (stack)
		{
			if (*max_num < stack -> num)
				*max_num = stack -> num;
			stack = stack -> next;
		}
	}
	stack = temp;
	if (min_num)
	{
		*min_num = stack -> num;
		while (stack)
		{
			if (*min_num > stack -> num)
				*min_num = stack -> num;
			stack = stack -> next;
		}
	}
}

static int	is_pushed(t_list *stack_a, long bord_line)
{
	while (stack_a)
	{
		if (stack_a -> num < bord_line)
			return (0);
		stack_a = stack_a -> next;
	}
	return (1);
}

static void	divide_4(t_list **sa, t_list **sb, long b2, t_list_cmd *cmd_set)
{
	while (!is_pushed(*sa, b2))
	{
		if (ft_lstlast(*sa)-> num >= b2)
			rotate(*sa, cmd_set, 0);
		print_cmd(cmd_set);
		if (ft_lstlast(*sa)-> num < b2)
			push_b(sa, sb, 1);
	}
}

static void	sort_remain(t_list **sa, t_list **sb, int max, t_list_cmd *cmd_set)
{
	while (!is_sorted(*sa))
	{
		if (ft_lstlast(*sa)-> num != max)
			push_b(sa, sb, 1);
		else
			rotate(*sa, cmd_set, 0);
		print_cmd(cmd_set);
	}
}

void	sort_b(t_list **stack_a, t_list **stack_b, t_list_cmd **cmd_set)
{
	long	max_num;
	long	min_num;
	long	range;
	long	bord_line[3];

	get_max_min(*stack_a, &max_num, &min_num);
	range = max_num + 1 - min_num;
	bord_line[0] = min_num + 1 + range / 4;
	bord_line[1] = bord_line[0] + range / 4;
	bord_line[2] = bord_line[1] + range / 4;
	while (!is_pushed(*stack_a, bord_line[1]))
	{
		if (ft_lstlast(*stack_a)-> num >= bord_line[1])
			rotate(*stack_a, *cmd_set, 0);
		if ((*stack_b) && ft_lstlast(*stack_b)-> num <= bord_line[0])
			rotate(*stack_b, *cmd_set, 1);
		print_cmd(*cmd_set);
		if (ft_lstlast(*stack_a)-> num < bord_line[1])
			push_b(stack_a, stack_b, 1);
	}
	if (ft_lstlast(*stack_a)-> index > 9)
		divide_4(stack_a, stack_b, bord_line[2], *cmd_set);
	sort_remain(stack_a, stack_b, max_num, *cmd_set);
	get_data(*stack_a, *stack_b);
}
