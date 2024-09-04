/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:04:59 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/11 13:23:36 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	both_forks_chk(t_philo *philo)
{
	int	left;
	int	right;
	int	*forks;

	forks = philo -> g_data -> forks;
	left = get_left_fork_idx(philo);
	right = philo -> idx;
	pthread_mutex_lock(&(philo -> g_data -> fork[left]));
	if ((philo -> g_data -> forks)[left] == GRABBED)
	{
		pthread_mutex_unlock(&(philo -> g_data -> fork[left]));
		pthread_mutex_lock(&(philo -> g_data -> fork[right]));
		if ((philo -> g_data -> forks)[right] == GRABBED)
		{
			pthread_mutex_unlock(&(philo -> g_data -> fork[right]));
			return (TRUE);
		}
	}
	pthread_mutex_unlock(&(philo -> g_data -> fork[left]));
	pthread_mutex_unlock(&(philo -> g_data -> fork[right]));
	return (FALSE);
}

int	chk_left_right_forks(t_philo *philo)
{
	if (!(philo -> idx % 2))
		return (TRUE);
	else if (philo -> status -> ready_to_eat_flag == TRUE)
		return (TRUE);
	else if (both_forks_chk(philo))
		return (TRUE);
	return (FALSE);
}

int	ate_cnt_chk(t_g_da *g_data)
{
	if (g_data -> end_cnt < 0)
		return (ALIVE);
	pthread_mutex_lock(&(g_data -> ate_done));
	if (g_data -> ate_done_cnt == g_data -> max + 1)
	{
		pthread_mutex_unlock(&(g_data -> ate_done));
		return (DEAD);
	}
	pthread_mutex_unlock(&(g_data -> ate_done));
	return (ALIVE);
}
