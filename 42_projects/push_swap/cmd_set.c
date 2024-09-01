/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:39:11 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/21 16:28:32 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	int	temp;

	if (!stack || (!(stack -> next) && !(stack -> prev)))
		return ;
	stack = ft_lstlast(stack);
	temp = stack -> num;
	stack = stack -> prev;
	stack -> next -> num = stack -> num;
	stack -> num = temp;
}

void	push_a(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list	*new;
	t_list	*temp_b;

	if (!(*stack_b))
		return ;
	temp_b = ft_lstlast(*stack_b);
	new = ft_lstnew();
	if (!new)
		exit(1);
	ft_lstadd_back(stack_a, new);
	new -> num = temp_b -> num;
	if (temp_b -> prev)
	{
		temp_b -> prev -> next = 0;
		temp_b -> prev = 0;
	}
	else
		*stack_b = 0;
	free(temp_b);
	if (flag)
		ft_putstr_fd("pa\n", 1);
}

void	push_b(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list	*new;
	t_list	*temp_a;

	if (!(*stack_a))
		return ;
	temp_a = ft_lstlast(*stack_a);
	new = ft_lstnew();
	if (!new)
		exit(1);
	ft_lstadd_back(stack_b, new);
	new -> num = temp_a -> num;
	if (temp_a -> prev)
	{
		temp_a -> prev -> next = 0;
		temp_a -> prev = 0;
	}
	else
		*stack_a = 0;
	free(temp_a);
	if (flag)
		ft_putstr_fd("pb\n", 1);
}

void	rotate(t_list *stack, t_list_cmd *cmd_set, int b_flag)
{
	int	temp;

	if (!stack || (!(stack -> next) && !(stack -> prev)))
		return ;
	stack = ft_lstlast(stack);
	temp = stack -> num;
	while (stack -> prev)
	{
		stack -> num = stack -> prev -> num;
		stack = stack -> prev;
	}
	stack -> num = temp;
	if (cmd_set && b_flag)
		cmd_set -> rb_flag++;
	else if (cmd_set && !b_flag)
		cmd_set -> ra_flag++;
}

void	reverse_rotate(t_list *stack, t_list_cmd *cmd_set, int b_flag)
{
	int	temp;

	if (!stack || (!(stack -> next) && !(stack -> prev)))
		return ;
	while (stack -> prev)
		stack = stack -> prev;
	temp = stack -> num;
	while (stack -> next)
	{
		stack -> num = stack -> next -> num;
		stack = stack -> next;
	}
	stack -> num = temp;
	if (cmd_set && b_flag)
		cmd_set -> rrb_flag++;
	else if (cmd_set && !b_flag)
		cmd_set -> rra_flag++;
}
