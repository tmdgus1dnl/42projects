/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:22:17 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/05 16:35:14 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_list_cmd	*cmd_set;

	if (argc <= 1)
		return (1);
	if (error_chk(argc, argv) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	make_lst(&stack_a, &stack_b, argc, argv);
	if (is_sorted(stack_a))
		return (0);
	if (is_3_arg(stack_a) == 3)
	{
		small_sort(stack_a);
		return (0);
	}
	cmd_set = make_cmd_set();
	sort_b(&stack_a, &stack_b, &cmd_set);
	sort_a(&stack_a, &stack_b, &cmd_set);
	clear_mem(&stack_a, &cmd_set);
	return (0);
}
