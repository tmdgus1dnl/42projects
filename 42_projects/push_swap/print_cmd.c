/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:55:36 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/18 11:52:10 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_rotate(t_list_cmd *cmd_set)
{
	while (cmd_set -> ra_flag && cmd_set -> rb_flag)
	{
		ft_putstr_fd("rr\n", 1);
		cmd_set -> ra_flag--;
		cmd_set -> rb_flag--;
	}
	while (cmd_set -> ra_flag && !(cmd_set -> rb_flag))
	{
		ft_putstr_fd("ra\n", 1);
		cmd_set -> ra_flag--;
	}
	while (!(cmd_set -> ra_flag) && cmd_set -> rb_flag)
	{
		ft_putstr_fd("rb\n", 1);
		cmd_set -> rb_flag--;
	}
}

static void	print_reverse_rotate(t_list_cmd *cmd_set)
{
	while (cmd_set -> rra_flag && cmd_set -> rrb_flag)
	{
		ft_putstr_fd("rrr\n", 1);
		cmd_set -> rra_flag--;
		cmd_set -> rrb_flag--;
	}
	while (cmd_set -> rra_flag && !(cmd_set -> rrb_flag))
	{
		ft_putstr_fd("rra\n", 1);
		cmd_set -> rra_flag--;
	}
	while (!(cmd_set -> rra_flag) && cmd_set -> rrb_flag)
	{
		ft_putstr_fd("rrb\n", 1);
		cmd_set -> rrb_flag--;
	}
}

void	print_cmd(t_list_cmd *cmd_set)
{
	print_rotate(cmd_set);
	print_reverse_rotate(cmd_set);
}
