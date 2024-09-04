/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:44:46 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/11 13:08:35 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	change_action(t_philo *philo)
{
	if (philo -> status -> action == SLEEP)
	{
		print_think(philo);
		philo -> status -> action = THINK;
	}
	else if (philo -> status -> action == EAT)
	{
		print_sleep(philo);
		philo -> status -> action = SLEEP;
	}
}

void	ph_sleep(t_philo *philo)
{
	if (!do_act(philo -> g_data -> time_to_sleep, philo))
		return ;
	change_action(philo);
	return ;
}

void	ph_eat(t_philo *philo)
{
	if (!do_act(philo -> g_data -> time_to_eat, philo))
		return ;
	put_down_forks(philo);
	philo -> status -> time_left = philo -> g_data -> time_to_die;
	(philo -> status -> ate_cnt)++;
	if (philo -> status -> ate_cnt >= philo -> g_data -> end_cnt)
	{
		if (philo -> status -> ate_done_flag == FALSE)
		{
			philo -> status -> ate_done_flag = TRUE;
			pthread_mutex_lock(&(philo -> g_data -> ate_done));
			(philo -> g_data -> ate_done_cnt)++;
			pthread_mutex_unlock(&(philo -> g_data -> ate_done));
		}
	}
	change_action(philo);
	return ;
}

int	eat_even_first(t_philo *philo)
{
	if (!(philo -> idx % 2))
	{
		if (!pick_up_forks(philo))
			return (FALSE);
		else
		{
			print_eat(philo);
			philo -> status -> action = EAT;
			return (TRUE);
		}
	}
	return (FALSE);
}
