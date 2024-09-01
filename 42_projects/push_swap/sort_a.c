/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:04:18 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/22 14:58:41 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_data(t_list *stack_a, t_list *stack_b)
{
	get_gap(stack_a, stack_b);
	get_weight(stack_b, get_half_idx(stack_b));
}

static void	last_sort(t_list *stack_a, t_list_cmd *cmd_set)
{
	t_list	*max_num_node;
	t_list	*temp;

	temp = stack_a;
	max_num_node = stack_a;
	while (stack_a)
	{
		if (max_num_node -> num < stack_a -> num)
			max_num_node = stack_a;
		stack_a = stack_a -> next;
	}
	stack_a = temp;
	while (!is_sorted(stack_a))
	{
		if (max_num_node -> index >= get_half_idx(stack_a))
			rotate(stack_a, cmd_set, 0);
		else
			reverse_rotate(stack_a, cmd_set, 0);
		print_cmd(cmd_set);
	}
}

static void	is_rb_rrb(t_list *stack_a, t_list *stack_b, t_list_cmd *cmd_set)
{
	stack_b = get_min_weight(stack_b);
	if (stack_b && stack_b -> index >= get_half_idx(stack_b))
	{
		if (stack_b -> index != ft_lstlast(stack_b)-> index)
			rotate(stack_b, cmd_set, 1);
	}
	if (stack_b && stack_b -> index < get_half_idx(stack_b))
		reverse_rotate(stack_b, cmd_set, 1);
	get_data(stack_a, stack_b);
}

void	sort_a(t_list **stack_a, t_list **stack_b, t_list_cmd **cmd_set)
{
	while (*stack_b)
	{
		if (get_min_weight(*stack_b) == ft_lstlast(*stack_b) && (*stack_b))
		{
			if (ft_lstlast(*stack_b)-> num < ft_lstlast(*stack_a)-> num)
			{
				print_cmd(*cmd_set);
				push_a(stack_a, stack_b, 1);
			}
			else
				is_a_small(*stack_a, *stack_b, *cmd_set);
			get_data(*stack_a, *stack_b);
		}
		is_rb_rrb(*stack_a, *stack_b, *cmd_set);
		is_a_big(*stack_a, *stack_b, *cmd_set);
	}
	last_sort(*stack_a, *cmd_set);
}
