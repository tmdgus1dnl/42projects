/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:57:54 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/22 14:26:05 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_min_gap(t_list *stack_a, long targ_num)
{
	t_list	*temp;
	long	min_gap;

	temp = stack_a;
	while (stack_a)
	{
		if (stack_a -> num > targ_num)
		{
			min_gap = stack_a -> gap;
			break ;
		}
		stack_a = stack_a -> next;
	}
	stack_a = temp;
	while (stack_a)
	{
		if (stack_a -> gap <= min_gap && stack_a -> num > targ_num)
			min_gap = stack_a -> gap;
		stack_a = stack_a -> next;
	}
	return (min_gap);
}

static int	get_small_min_gap(t_list *stack_a)
{
	t_list	*temp;
	long	min_gap;

	temp = stack_a;
	min_gap = stack_a -> gap;
	while (stack_a -> next)
	{
		if (stack_a -> gap <= min_gap)
			min_gap = stack_a -> gap;
		stack_a = stack_a -> next;
	}
	stack_a = temp;
	while (stack_a -> next)
	{
		if (min_gap == stack_a -> gap)
			return (stack_a -> index);
		stack_a = stack_a -> next;
	}
	return (stack_a -> index);
}

static int	get_big_min_gap(t_list *stack_a, t_list *stack_b)
{
	int		last_b_num;
	long	min_gap;

	min_gap = get_min_gap(stack_a, ft_lstlast(stack_b)-> num);
	last_b_num = ft_lstlast(stack_b)-> num;
	while (stack_a -> next)
	{
		if (min_gap == stack_a -> gap && stack_a -> num > last_b_num)
			return (stack_a -> index);
		stack_a = stack_a -> next;
	}
	return (stack_a -> index);
}

void	is_a_big(t_list *stack_a, t_list *stack_b, t_list_cmd *cmd_set)
{
	int		last_a_num;

	if (!stack_b || !stack_a)
		return ;
	last_a_num = ft_lstlast(stack_a)-> num;
	while (stack_a -> num < last_a_num)
	{
		if (get_min_weight(stack_b) != ft_lstlast(stack_b))
			break ;
		else if (stack_a -> num > ft_lstlast(stack_b)-> num)
		{
			if (get_small_min_gap(stack_a) >= get_half_idx(stack_a))
				rotate(stack_a, cmd_set, 0);
			else
				reverse_rotate(stack_a, cmd_set, 0);
		}
		else
			break ;
		last_a_num = ft_lstlast(stack_a)-> num;
		get_data(stack_a, stack_b);
	}
	get_data(stack_a, stack_b);
}

void	is_a_small(t_list *stack_a, t_list *stack_b, t_list_cmd *cmd_set)
{
	while (get_big_min_gap(stack_a, stack_b) != ft_lstlast(stack_a)-> index)
	{
		if (get_big_min_gap(stack_a, stack_b) >= get_half_idx(stack_a))
			rotate(stack_a, cmd_set, 0);
		else
			reverse_rotate(stack_a, cmd_set, 0);
		get_data(stack_a, stack_a);
	}
}
