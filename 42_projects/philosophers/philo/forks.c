/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:52:45 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/11 13:08:19 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_left_fork_idx(t_philo *philo)
{
	if (philo -> idx == 0)
		return (philo -> g_data -> max);
	else
		return ((philo -> idx) - 1);
}

static void	pick_up_fork(t_philo *philo, int direct, int fork_idx)
{
	int				*forks;

	forks = philo -> g_data -> forks;
	if (chk_fork_status(philo, fork_idx))
	{
		print_pick_up_fork(philo);
		if (direct == LEFT)
			philo -> status -> left_hand = BUSY;
		else
			philo -> status -> right_hand = BUSY;
	}
}

int	pick_up_forks(t_philo *philo)
{
	int	*forks;
	int	left_fork;
	int	right_fork;

	left_fork = get_left_fork_idx(philo);
	right_fork = philo -> idx;
	forks = philo -> g_data -> forks;
	if (philo -> status -> left_hand == FREE)
		pick_up_fork(philo, LEFT, left_fork);
	if (philo -> status -> right_hand == FREE)
		pick_up_fork(philo, RIGHT, right_fork);
	if (!philo -> status -> left_hand && !philo -> status -> right_hand)
		return (TRUE);
	else
		return (FALSE);
}

void	put_down_forks(t_philo *philo)
{
	int	*forks;

	forks = philo -> g_data -> forks;
	drop_fork(philo, get_left_fork_idx(philo));
	drop_fork(philo, philo -> idx);
	philo -> status -> left_hand = FREE;
	philo -> status -> right_hand = FREE;
}
