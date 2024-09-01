/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:31:35 by seunghan          #+#    #+#             */
/*   Updated: 2024/02/14 16:42:55 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_list_cmd
{
	int	ra_flag;
	int	rra_flag;
	int	rb_flag;
	int	rrb_flag;
}	t_list_cmd;

int			error_chk(int argc, char **argv);
int			is_sorted(t_list *stack);
int			get_half_idx(t_list *stack);
int			is_3_arg(t_list *stack);
long		get_min_gap(t_list *stack_a, long targ_num);
void		make_lst(t_list **stack_a, t_list **stack_b, int argc, char **argv);
void		get_max_min(t_list *stack, long *max_num, long *min_num);
void		get_num(t_list *stack_a);
void		swap(t_list *stack);
void		push_a(t_list **stack_a, t_list **stack_b, int flag);
void		push_b(t_list **stack_a, t_list **stack_b, int flag);
void		rotate(t_list *stack, t_list_cmd *cmd_set, int flag);
void		reverse_rotate(t_list *stack, t_list_cmd *cmd_set, int flag);
void		is_a_small(t_list *stack_a, t_list *stack_b, t_list_cmd *cmd_set);
void		is_a_big(t_list *stack_a, t_list *stack_b, t_list_cmd *cmd_set);
void		small_sort(t_list *stack_a);
void		sort_a(t_list **stack_a, t_list **stack_b, t_list_cmd **cmd_set);
void		sort_b(t_list **stack_a, t_list **stack_b, t_list_cmd **cmd_set);
void		print_cmd(t_list_cmd *cmd_set);
void		get_gap(t_list *stack_a, t_list *stack_b);
void		get_weight(t_list *stack, int half_idx);
void		get_data(t_list *stack_a, t_list *stack_b);
void		clear_mem(t_list **stack, t_list_cmd **cmd_set);
t_list		*get_min_weight(t_list *stack);
t_list_cmd	*make_cmd_set(void);

#endif
