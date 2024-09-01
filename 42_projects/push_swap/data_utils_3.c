/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:27:44 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/22 14:59:35 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_mem(t_list **stack, t_list_cmd **cmd_set)
{
	t_list	*temp;

	if (!(*stack))
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)-> next;
		free(temp);
	}
	if (cmd_set)
		free(*cmd_set);
}

static void	num_transfer(t_list *stack)
{
	while (stack)
	{
		stack -> num = stack -> weight;
		stack = stack -> next;
	}
}

static void	get_gap_a(t_list *stack_a, long min_num)
{
	while (stack_a)
	{
		stack_a -> gap = (stack_a -> num) - min_num;
		stack_a = stack_a -> next;
	}
}

static long	get_min_num(t_list *stack, long min_gap, long min_num)
{
	while (stack)
	{
		if (min_gap == stack -> gap && stack -> num > min_num)
		{
			min_num = stack -> num;
			break ;
		}
		stack = stack -> next;
	}
	return (min_num);
}

void	get_num(t_list *stack_a)
{
	t_list	*temp;
	long	min_num;
	long	new_num;

	new_num = 1;
	temp = stack_a;
	get_max_min(stack_a, 0, &min_num);
	while (new_num != (ft_lstlast(stack_a)-> index) + 2)
	{
		get_gap_a(stack_a, min_num);
		while (stack_a)
		{
			if (min_num == stack_a -> num)
			{
				stack_a -> weight = new_num;
				break ;
			}
			stack_a = stack_a -> next;
		}
		stack_a = temp;
		min_num = get_min_num(stack_a, get_min_gap(stack_a, min_num), min_num);
		new_num++;
	}
	num_transfer(stack_a);
}
