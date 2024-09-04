/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:55:05 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/04 21:30:13 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	end_chk(t_philo *philo)
{
	pthread_mutex_lock(&(philo -> g_data -> end));
	if (philo -> g_data -> end_flag)
	{
		pthread_mutex_unlock(&(philo -> g_data -> end));
		return (DEAD);
	}
	pthread_mutex_unlock(&(philo -> g_data -> end));
	return (ALIVE);
}

int	time_left_chk(t_philo *philo)
{
	if (philo -> status -> time_left <= 0)
	{
		philo -> status -> action = DEAD;
		pthread_mutex_unlock(&(philo -> g_data -> over));
		print_dead(philo);
		return (DEAD);
	}
	return (ALIVE);
}

static int	try_forks(t_philo *philo)
{
	if (!pick_up_forks(philo))
		return (FALSE);
	else
	{
		print_eat(philo);
		philo -> status -> action = EAT;
		return (TRUE);
	}
	return (FALSE);
}

int	chk_eat_possible(t_philo *philo)
{
	if (!(philo -> status -> ate_cnt))
	{
		if (eat_even_first(philo))
			return (TRUE);
		if (!chk_left_right_forks(philo))
			return (FALSE);
		else
			philo -> status -> ready_to_eat_flag = TRUE;
	}
	if (try_forks(philo))
		return (TRUE);
	return (FALSE);
}
