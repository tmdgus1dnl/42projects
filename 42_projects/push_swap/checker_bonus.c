/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:11:54 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/25 12:00:18 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line_bonus.h"

static int	str_chk(char *str)
{
	if (!ft_strncmp(str, "sa\n", 5))
		return (1);
	else if (!ft_strncmp(str, "sb\n", 5))
		return (1);
	else if (!ft_strncmp(str, "ss\n", 5))
		return (1);
	else if (!ft_strncmp(str, "ra\n", 5))
		return (1);
	else if (!ft_strncmp(str, "rb\n", 5))
		return (1);
	else if (!ft_strncmp(str, "rr\n", 5))
		return (1);
	else if (!ft_strncmp(str, "rra\n", 5))
		return (1);
	else if (!ft_strncmp(str, "rrb\n", 5))
		return (1);
	else if (!ft_strncmp(str, "rrr\n", 5))
		return (1);
	else if (!ft_strncmp(str, "pa\n", 5))
		return (1);
	else if (!ft_strncmp(str, "pb\n", 5))
		return (1);
	else if (!ft_strncmp(str, "\n", 2))
		return (1);
	return (-1);
}

static void	do_cmd_1(t_list *stack_a, t_list *stack_b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 5))
		swap(stack_a);
	else if (!ft_strncmp(str, "sb\n", 5))
		swap(stack_b);
	else if (!ft_strncmp(str, "ss\n", 5))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (!ft_strncmp(str, "ra\n", 5))
		rotate(stack_a, 0, 0);
	else if (!ft_strncmp(str, "rb\n", 5))
		rotate(stack_b, 0, 0);
	else if (!ft_strncmp(str, "rr\n", 5))
	{
		rotate(stack_a, 0, 0);
		rotate(stack_b, 0, 0);
	}
}

static void	do_cmd_2(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strncmp(str, "rra\n", 5))
		reverse_rotate(*stack_a, 0, 0);
	else if (!ft_strncmp(str, "rrb\n", 5))
		reverse_rotate(*stack_b, 0, 0);
	else if (!ft_strncmp(str, "rrr\n", 5))
	{
		reverse_rotate(*stack_a, 0, 0);
		reverse_rotate(*stack_b, 0, 0);
	}
	else if (!ft_strncmp(str, "pa\n", 5))
		push_a(stack_a, stack_b, 0);
	else if (!ft_strncmp(str, "pb\n", 5))
		push_b(stack_a, stack_b, 0);
	free(str);
}

static void	print_status(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a) && !(*stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clear_mem(stack_a, 0);
	clear_mem(stack_b, 0);
}

int	main(int argc, char **argv)
{
	char	*str;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc <= 1)
		return (1);
	if (error_chk(argc, argv) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	make_lst(&stack_a, &stack_b, argc, argv);
	str = get_next_line(0);
	while (str)
	{
		if (str_chk(str) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		do_cmd_1(stack_a, stack_b, str);
		do_cmd_2(&stack_a, &stack_b, str);
		str = get_next_line(0);
	}
	print_status(&stack_a, &stack_b);
}
