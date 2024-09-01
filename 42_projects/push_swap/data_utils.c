/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:57:54 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/21 11:48:47 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack -> next)
	{
		if (stack -> num < stack -> next -> num)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

void	get_gap(t_list *stack_a, t_list *stack_b)
{
	int		last_num;
	t_list	*temp;

	if (!stack_a || !stack_b)
		return ;
	temp = stack_b;
	last_num = ft_lstlast(stack_a)-> num;
	while (stack_b)
	{
		if (last_num > (stack_b -> num))
			stack_b -> gap = last_num - (stack_b -> num);
		else
			stack_b -> gap = (stack_b -> num) - last_num;
		stack_b = stack_b -> next;
	}
	stack_b = temp;
	last_num = ft_lstlast(stack_b)-> num;
	while (stack_a)
	{
		if (last_num > stack_a -> num)
			stack_a -> gap = last_num - stack_a -> num;
		else
			stack_a -> gap = stack_a -> num - last_num;
		stack_a = stack_a -> next;
	}
}

int	get_half_idx(t_list *stack)
{
	int	half_idx;

	if (!stack)
		return (0);
	stack = ft_lstlast(stack);
	half_idx = (stack -> index) / 2;
	return (half_idx);
}

void	get_weight(t_list *stack, int half_idx)
{
	int		idx;
	long	gap;

	if (!stack)
		return ;
	while (stack -> prev)
		stack = stack -> prev;
	while (stack)
	{
		idx = stack -> index;
		gap = stack -> gap;
		if (idx < half_idx)
			stack -> weight = gap + idx + 1;
		else
			stack -> weight = gap + half_idx - (idx - half_idx);
		stack = stack -> next;
	}
}

t_list	*get_min_weight(t_list *stack)
{
	long	min_weight;
	t_list	*temp;

	if (!stack)
		return (0);
	temp = stack;
	min_weight = stack -> weight;
	while (stack)
	{
		if (min_weight > stack -> weight)
			min_weight = stack -> weight;
		stack = stack -> next;
	}
	stack = temp;
	while (stack)
	{
		if (min_weight == stack -> weight)
			break ;
		stack = stack -> next;
	}
	return (stack);
}
