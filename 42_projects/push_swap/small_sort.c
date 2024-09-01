/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:54:14 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/16 16:55:54 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_3_arg(t_list *stack)
{
	int	arg_count;

	arg_count = 0;
	while (stack)
	{
		arg_count++;
		stack = stack -> next;
	}
	return (arg_count);
}

static void	get_m_num(t_list *stack, int *max, int *mid, int *min)
{
	t_list	*temp;

	temp = stack;
	*max = stack -> num;
	*min = stack -> num;
	while (stack)
	{
		if (*max < stack -> num)
			*max = stack -> num;
		if (*min > stack -> num)
			*min = stack -> num;
		stack = stack -> next;
	}
	stack = temp;
	while (stack)
	{
		if (*max != stack -> num && *min != stack -> num)
			*mid = stack -> num;
		stack = stack -> next;
	}
}

void	small_sort(t_list *stack_a)
{
	int	max;
	int	mid;
	int	min;

	get_m_num(stack_a, &max, &mid, &min);
	if (mid == ft_lstlast(stack_a)-> num && max == stack_a -> num)
		ft_putstr_fd("sa\n", 1);
	else if (mid == ft_lstlast(stack_a)-> num && min == stack_a -> num)
		ft_putstr_fd("rra\n", 1);
	else if (max == ft_lstlast(stack_a)-> num && min == stack_a -> num)
		ft_putstr_fd("rra\nrra\nsa\n", 1);
	else if (max == ft_lstlast(stack_a)-> num && mid == stack_a -> num)
		ft_putstr_fd("rra\nrra\n", 1);
	else if (min == ft_lstlast(stack_a)-> num && mid == stack_a -> num)
		ft_putstr_fd("ra\nsa\nrra\n", 1);
}
