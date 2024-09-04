/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_race.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:48:15 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/11 13:20:05 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	chk_fork_status(t_philo *philo, int idx)
{
	pthread_mutex_lock(&(philo -> g_data -> fork[idx]));
	if ((philo -> g_data -> forks)[idx] == DROPPED)
	{
		(philo -> g_data -> forks)[idx] = GRABBED;
		pthread_mutex_unlock(&(philo -> g_data -> fork[idx]));
		return (TRUE);
	}
	else
	{
		pthread_mutex_unlock(&(philo -> g_data -> fork[idx]));
		return (FALSE);
	}
}

void	drop_fork(t_philo *philo, int idx)
{
	pthread_mutex_lock(&(philo -> g_data -> fork[idx]));
	(philo -> g_data -> forks)[idx] = DROPPED;
	pthread_mutex_unlock(&(philo -> g_data -> fork[idx]));
	return ;
}
